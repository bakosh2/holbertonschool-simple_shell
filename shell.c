#include "simple_shell.h"

/**
 * execute_cmd - execute a command with PATH handling
 * @cmd: command line
 * @prog_name: shell name
 *
 * Return: 0 always
 */
int execute_cmd(char *cmd, char *prog_name)
{
	char **argv;
	char *path;
	pid_t pid;
	int status;


	argv = split_line(cmd);
	if (!argv || !argv[0])
	{
		free_argv(argv);
		return (0);
	}

	if (strchr(argv[0], '/'))
		path = strdup(argv[0]);
	else
		path = find_in_path(argv[0]);

	if (!path)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, argv[0]);
		free_argv(argv);
		return (0); /* NO fork */
	}

	pid = fork();
	if (pid == 0)
	{
		execve(path, argv, environ);
		exit(127);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}

	free(path);
	free_argv(argv);
	return (0);
}
