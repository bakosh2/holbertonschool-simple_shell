#include "simple_shell.h"

/**
* main - Entry point of the simple shell
* @ac: argument count (unused)
* @av: argument vector (unused)
* @env: environment variables
*
* Return: 0
*/
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	char *line = NULL;

	size_t len = 0;
	char **tokens = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		tokens = tokenization(line, " \n");
		execution(tokens, env);
		free_array(tokens);
	}

	free(line);
	return (0);
}
