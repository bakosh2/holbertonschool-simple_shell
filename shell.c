#include "simple_shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char *argv[1024]; /* ثابت الحجم لتجنب مشكلة pedantic */

    while ((nread = getline(&line, &len, stdin)) != -1)
    {
        if (nread == 1) /* Empty line */
            continue;

        line[nread - 1] = '\0'; /* Remove newline */

        /* تحويل السطر إلى argv */
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
        if (pid == 0) /* Child */
        {
            execve(argv[0], argv, environ);
            perror("./hsh"); /* Error if command not found */
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

