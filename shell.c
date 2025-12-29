#include "simple_shell.h"

/**
 * execute_cmd - Execute a command with its arguments
 * @cmd: command line entered by the user
 * @prog_name: name of the shell (argv[0])
 * @env: environment variables
 *
 * Return: 0 on success
 */
int execute_cmd(char *cmd, char *prog_name, char **env)
{
	pid_t pid;
	int status;
	char *argv_exec[64];
	char *token;
	int i = 0;

	(void)prog_name;

	if (cmd == NULL || *cmd == '\0')
		return (0);

	/* Split command into arguments */
	token = strtok(cmd, " \t");
	while (token && i < 63)
	{
		argv_exec[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv_exec[i] = NULL;

	if (argv_exec[0] == NULL)
		return (0);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}

	if (pid == 0)
	{
		execve(argv_exec[0], argv_exec, env);
		perror(argv_exec[0]);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (0);
}

