#include "simple_shell.h"

/**
* execution - executes a command
* @tokens: tokenized command
* @env: environment variables
*
* Return: 0
*/
int execution(char **tokens, char **env)
{
	char *cmd_path;

	pid_t pid;
	int status;

	if (!tokens || !tokens[0])
		return (0);

	cmd_path = find_command(tokens[0], env);
	if (!cmd_path)
	{
		write(2, "./hsh: 1: ", 10);
		write(2, tokens[0], _strlen(tokens[0]));
		write(2, ": not found\n", 12);
		return (0); /* ❗ NO fork */
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, tokens, env) == -1)
			exit(1);
	}
	else
		wait(&status);

	free(cmd_path);
	return (0);
}
