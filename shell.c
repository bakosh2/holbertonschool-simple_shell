#include "simple_shell.h"

/**
* _exec_cmd - execute a command using execve
* @cmd: command to execute (full path)
* @prog_name: name of the shell (argv[0])
* @env: environment variables
* Return: 0 on success, -1 on failure
*/
int _exec_cmd(char *cmd, char *prog_name, char **env)
{
	pid_t pid;
	int status;
	char *argv_exec[2];

	(void)prog_name; /* add for unused parameter for now */

	if (cmd == NULL || *cmd == '\0')
		return (-1);

	argv_exec[0] = cmd;
	argv_exec[1] = NULL;

	pid = fork();
	if (pid == -1)
	return (-1);

	if (pid == 0) /* child process */
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
