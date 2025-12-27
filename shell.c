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
	pid_t pid;
	int status;

	while (getline(&line, &len, stdin) != -1)
	{
		if (line[0] == '\n')
			continue;

		line[strcspn(line, "\n")] = '\0';

		pid = fork();
		if (pid == 0)
		{
			char *argv[] = {line, NULL};

			execve(line, argv, environ);
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

