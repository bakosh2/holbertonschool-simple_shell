#include "simple_shell.h"

/**
 * main - Entry point for the simple shell program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (success)
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	(void)argc;

	while (1) /* Infinite loop for the shell prompt */
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

			execute_cmd(line, argv[0]);
	}

	free(line);
	return (0);
}
