#include "simple_shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * shell_loop - Runs the main loop of the simple shell
 */
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

        pid = fork();
        if (pid == 0) /* Child */
        {
            char *argv[] = {line, NULL};
            execve(argv[0], argv, environ);
            /* If execve fails */
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
        else if (pid > 0) /* Parent */
        {
            wait(&status);
        }
        else
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }
    free(line);
}

