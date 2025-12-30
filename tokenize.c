#include "simple_shell.h"

/**
 * tokenization - extract tokens from the getline command
 * @ptr: String of the command line
 * @delim: Delimiter
 *
 * Return: the array of tokens
 */
char **tokenization(char *ptr, char *delim)
{
	char *token = NULL, **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 10);
	if (!tokens)
		return (NULL);

	token = strtok(ptr, delim);
	while (token)
	{
		tokens[i] = _strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
