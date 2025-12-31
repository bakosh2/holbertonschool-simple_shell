#include "simple_shell.h"

/**
* main - simple shell main loop
* @ac: argument count
* @av: argument vector
* @env: environment variables
*
* Return: 0 on success
*/
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t len = 0;
	char **tokens = NULL;
	(void)ac;   /* unused */

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
		execution(tokens, env, av[0]);
		free_array(tokens);
	}

	free(line);
	return (0);
}
