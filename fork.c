#include "simple_shell.h"

/**
 * split_line - split command line into argv
 * @line: input
 *
 * Return: NULL-terminated argv
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

/**
 * free_argv - free argv array
 * @argv: argument vector
 */
void free_argv(char **argv)
{
	int i;

	if (!argv)
		return;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}
