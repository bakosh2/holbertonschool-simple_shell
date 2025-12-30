#include "simple_shell.h"

/**
 * resolve_path - find executable path
 * @cmd: command name
 *
 * Return: malloc'd path or NULL
 */
char *resolve_path(char *cmd)
{
	char *path_env, *copy, *dir, *full;
	int len;

	if (strchr(cmd, '/'))
		return (access(cmd, X_OK) == 0 ? strdup(cmd) : NULL);

	path_env = getenv("PATH");
	if (!path_env || *path_env == '\0')
		return (NULL);

	copy = strdup(path_env);
	if (!copy)
		return (NULL);

	dir = strtok(copy, ":");
	while (dir)
	{
		len = strlen(dir) + strlen(cmd) + 2;
		full = malloc(len);
		if (!full)
		{
			free(copy);
			return (NULL);
		}

		snprintf(full, len, "%s/%s", dir, cmd);
		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (full);
		}

		free(full);
		dir = strtok(NULL, ":");
	}

	free(copy);
	return (NULL);
}
