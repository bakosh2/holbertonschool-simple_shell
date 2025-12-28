#include "simple_shell.h"

/**
* main - Entry point for the simple shell
* @argc: argument count (not used)
* @argv: argument vector
* @env: environment variables
* Return: 0 on success, or exit with status 1 on failure
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
		if (nread == -1) /* EOF */
		{
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
		break;
	}

		/* remove newline at end */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* skip leading spaces */
		cmd = line;
		while (*cmd == ' ' || *cmd == '\t')
			cmd++;

		/* if line is empty or spaces only, continue */
		if (*cmd == '\0')
			continue;

		if (_exec_cmd(cmd, argv[0], env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], cmd);
		}
	}

	free(line);
	return (0);
}
