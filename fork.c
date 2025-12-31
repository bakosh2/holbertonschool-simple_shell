#include "simple_shell.h"

/**
 * find_command - finds the full path of a command
 * @cmd: command name
 * @env: environment variables
 *
 * Return: full path if found, NULL otherwise
 */
char *find_command(char *cmd, char **env)
{
    char *path_env = NULL, *path_copy, *dir, *full;
    struct stat st;
    int i, len;

    /* If command starts with / or ./ or ../ → use it directly */
    if (cmd[0] == '/' || cmd[0] == '.')
    {
        if (stat(cmd, &st) == 0)
            return (_strdup(cmd));
        return (NULL);
    }

    /* Find PATH in environment */
    for (i = 0; env && env[i]; i++)
    {
        if (_strncmp(env[i], "PATH=", 5) == 0)
        {
            path_env = env[i] + 5;
            break;
        }
    }

    /* No PATH variable at all */
    if (!path_env)
        return (NULL);

    /* PATH="" → treat as no PATH */
    if (*path_env == '\0')
        return (NULL);

    /* Duplicate PATH so strtok doesn't modify env */
    path_copy = _strdup(path_env);
    if (!path_copy)
        return (NULL);

    dir = strtok(path_copy, ":");
    while (dir)
    {
        len = _strlen(dir) + _strlen(cmd) + 2;
        full = malloc(len);
        if (!full)
        {
            free(path_copy);
            return (NULL);
        }

        full[0] = '\0';
        _strcpy(full, dir);
        _strcat(full, "/");
        _strcat(full, cmd);

        if (stat(full, &st) == 0)
        {
            free(path_copy);
            return (full);
        }

        free(full);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}
