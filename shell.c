#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void shell_loop(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

    while ((nread = getline(&line, &len, stdin)) != -1)
    {
        if (nread == 1) /* Empty line */
            continue;

        line[nread - 1] = '\0'; /* Remove newline */

        /* Split line into argv */
        char *argv[1024];
        int i = 0;
        char *token = strtok(line, " \t");
        while (token)
        {
            argv[i++] = token;
            token = strtok(NULL, " \t");
        }
        argv[i] = NULL;

        if (argv[0] == NULL)
            continue;

        /* Fork and execute */
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

