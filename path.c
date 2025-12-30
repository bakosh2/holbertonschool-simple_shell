#include "simple_shell.h"

/**
 * find_in_path - search PATH for command
 * @cmd: command
 *
 * Return: malloc'd full path or NULL
 */
char *find_in_path(char *cmd)
{
	char *path_env = getenv("PATH");
	char *copy, *token, *full;
	int len;

	if (!path_env || *path_env == '\0')
		return (NULL);

	copy = strdup(path_env);
	if (!copy)
		return (NULL);

	token = strtok(copy, ":");
	while (token)
	{
		len = strlen(token) + strlen(cmd) + 2;
		full = malloc(len);
		if (!full)
		{
			free(copy);
			return (NULL);
		}
		snprintf(full, len, "%s/%s", token, cmd);

		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (full);
		}

		free(full);
		token = strtok(NULL, ":");
	}

	free(copy);
	return (NULL);
}
