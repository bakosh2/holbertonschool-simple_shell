#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

extern char **environ;

/**
 * shell_loop - Runs the main loop of the simple shell
 *
 * Reads input from the user, executes commands, and waits for child processes.
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t pid;
	int status;

	while (getline(&line, &len, stdin) != -1)
	{
		/* Skip empty lines */
		if (line[0] == '\n')
			continue;

		/* Remove trailing newline */
		line[strcspn(line, "\n")] = '\0';

		/* Fork a child process to execute the command */
		pid = fork();
		if (pid == 0)
		{
			/* Prepare argv array */
			char *argv[2];
			argv[0] = line;
			argv[1] = NULL;

			/* Execute command */
			execve(line, argv, environ);

			/* If execve fails */
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			/* Parent waits for child to finish */
			wait(&status);
		}
		else
		{
			/* Fork failed */
			perror("Fork failed");
			break;
		}
	}

	free(line);
}

