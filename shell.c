#include "simple_shell.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: 0 on success
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *cmd;
	char *p;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* remove trailing newline */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* skip leading spaces */
		p = line;
		while (*p == ' ' || *p == '\t')
			p++;

		/* ignore empty or spaces-only lines */
		if (*p == '\0')
			continue;

		cmd = p;

		if (execute_cmd(cmd, argv[0], env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], cmd);
		}
	}

	free(line);
	return (0);
}
