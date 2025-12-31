#include "simple_shell.h"

/**
 * execution - executes a command by forking a child process
 * @tokens: array of command and its arguments
 * @env: environment variables
 * @prog_name: shell name
 *
 * Return: 0
 */
int execution(char **tokens, char **env, char *prog_name)
{
	char *cmd_path;
	pid_t pid;
	int status;

	cmd_path = find_command(tokens[0], env);
	if (!cmd_path)
	{
		write(2, prog_name, _strlen(prog_name));
		write(2, ": 1: ", 5);
		write(2, tokens[0], _strlen(tokens[0]));
		write(2, ": not found\n", 12);
		return (127); /* NO fork */
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, tokens, env);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);

	 free(cmd_path);
    return (WEXITSTATUS(status));
}
