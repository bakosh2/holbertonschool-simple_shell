#include "simple_shell.h"

/**
 * execute_cmd - execute a command using execve
 * @cmd: command line
 * @prog_name: name of the shell
 * @env: environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int execute_cmd(char *cmd, char *prog_name, char **env)
{
	pid_t pid;
	int status;
	char *argv_exec[3];
	char *arg = NULL;
	char *p;

	(void)prog_name;

	if (cmd == NULL || *cmd == '\0')
		return (-1);

	/* extract optional single argument */
	p = cmd;
	while (*p && *p != ' ' && *p != '\t')
		p++;

	if (*p)
	{
		*p = '\0';
		p++;
		while (*p == ' ' || *p == '\t')
			p++;
		if (*p)
			arg = p;
	}

	argv_exec[0] = cmd;
	argv_exec[1] = arg;
	argv_exec[2] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

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
