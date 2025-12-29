#include "simple_shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: argument count (unused)
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

	(void)argc;

	while (1)
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

		cmd = line;
		while (*cmd == ' ' || *cmd == '\t')
			cmd++;

		if (*cmd == '\0')
			continue;

		/* Cut at first space: NO arguments allowed in task 2 */
		{
			char *p = cmd;

			while (*p && *p != ' ' && *p != '\t')
				p++;
			*p = '\0';
		}

		if (execute_cmd(cmd, argv[0], env) == -1)
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], cmd);
	}

	free(line);
	return (0);
}
