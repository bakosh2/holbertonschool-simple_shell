#include "simple_shell.h"

/**
 * split_line - tokenize input line
 * @line: input
 *
 * Return: argv
 */
char **split_line(char *line)
{
	char **argv;
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * 64);
	if (!argv)
		return (NULL);

	token = strtok(line, " \t");
	while (token)
	{
		argv[i++] = strdup(token);
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;

	return (argv);
}
