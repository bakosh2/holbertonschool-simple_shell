#include "simple_shell.h"

/**
 * execute_cmd - Executes a command using execve
 * @cmd: command to execute (single word, full path)
 * @prog_name: program name
 * @env: environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int execute_cmd(char *cmd, char *prog_name, char **env)
{
	pid_t pid;
	int status;
	char *argv_exec[2];

	(void)prog_name;

	if (cmd == NULL || *cmd == '\0')
		return (-1);

	argv_exec[0] = cmd;
	argv_exec[1] = NULL;

	pid = fork();
	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		execve(cmd, argv_exec, env);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (0);
}
