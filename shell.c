#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

extern char **environ;

/**
 * shell_loop - Runs the main loop of the simple shell
 */
void shell_loop(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *argv[1024];
    pid_t pid;
    int status;

    while ((nread = getline(&line, &len, stdin)) != -1)
    {
        if (nread == 1) /* Empty line with just '\n' */
            continue;

        line[nread - 1] = '\0'; /* Remove trailing newline */

        /* Tokenize the line into commands separated by spaces/tabs */
        int i = 0;
        char *token = strtok(line, " \t");
        while (token != NULL)
        {
            argv[i++] = token;
            token = strtok(NULL, " \t");
        }
        argv[i] = NULL;

        if (argv[0] == NULL)
            continue;

        pid = fork();
        if (pid == 0)
        {
            execve(argv[0], argv, environ);
            perror("Error");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
        }
    }
    free(line);
}

