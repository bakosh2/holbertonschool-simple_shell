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
	char **argv = NULL;

	char *path = NULL;

	pid_t pid;

	argv = split_line(cmd);
	if (!argv || !argv[0])
	{
		free_argv(argv);
		return (0);
	}

	if (strchr(argv[0], '/'))	/* absolute or relative path */
		path = strdup(argv[0]);
	else
		path = find_in_path(argv[0]);

	if (!path)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, argv[0]);
		free_argv(argv);
		return (0);	/* IMPORTANT: no fork */
	}

	pid = fork();
	if (pid == 0)
	{
	if (pid == 0)
	{
		execv(path, argv);
		exit(127);
	}

	free(path);
	free_argv(argv);
	}

	return (0);
}
