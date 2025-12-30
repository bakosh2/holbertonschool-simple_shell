#include "simple_shell.h"

/**
 * free_array - frees a NULL-terminated array of strings
 * @tokens: array of strings to free
 */
void free_array(char **tokens)
{
	int i;

	if (!tokens)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}
