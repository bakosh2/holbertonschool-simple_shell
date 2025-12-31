#include "simple_shell.h"

/**
 * main - Entry point of the simple shell
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: last exit status of executed command
 */
int main(int argc, char **argv, char **env)
{
    char *line = NULL, *token;
    char *tokens[64];
    size_t len = 0;
    ssize_t nread;
    int i;
    int last_status = 0;

    (void)argc;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "#cisfun$ ", 9);

        nread = getline(&line, &len, stdin);
        if (nread == -1)
            break;

        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        token = strtok(line, " \t");
        i = 0;
        while (token && i < 63)
        {
            tokens[i++] = token;
            token = strtok(NULL, " \t");
        }
        tokens[i] = NULL;

        if (tokens[0])
        {
            if (_strcmp(tokens[0], "exit") == 0)
            {
                free(line);
                exit(0);
            }
            else if (_strcmp(tokens[0], "env") == 0)
            {
                /* Print all environment variables */
                for (i = 0; env[i]; i++)
                {
                    write(STDOUT_FILENO, env[i], _strlen(env[i]));
                    write(STDOUT_FILENO, "\n", 1);
                }
                last_status = 0;
            }
            else
            {
                last_status = execution(tokens, env, argv[0]);
            }
        }
    }

    free(line);
    return (last_status);
}

