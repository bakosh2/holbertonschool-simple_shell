#include "simple_shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

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

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "#cisfun$ ", 9);

        nread = getline(&line, &len, stdin);
        if (nread == -1) /* Ctrl+D */
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        if (nread > 0 && line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (line[0] == '\0') /* Empty line */
            continue;

        pid = fork();
        if (pid == 0) /* Child process */
        {
            char *argv[] = {line, NULL};

            execve(line, argv, environ);
            /* If execve fails */
            fprintf(stderr, "%s: No such file or directory\n", line);
            exit(EXIT_FAILURE);
        }
        else if (pid > 0) /* Parent process */
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

