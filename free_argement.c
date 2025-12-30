#include "simple_shell.h"

/**
 * free_argv - free argv
 * @argv: argument vector
 */
void free_argv(char **argv) /* free argv */
{
	int i;

	if (!argv)
		return;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}
