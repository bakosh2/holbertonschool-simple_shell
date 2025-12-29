#include "simple_shell.h"

/**
 * execute_cmd - Executes a command by forking a child process
 * @argv: argument vector (command and its arguments)
 * @prog_name: name of the program (for error messages)
 * @env: environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int execute_cmd(char **argv, char *prog_name, char **env)
{
	pid_t pid;
	int status;

	if (argv == NULL || argv[0] == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		execve(argv[0], argv, env);
		perror(prog_name);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (0);
}
