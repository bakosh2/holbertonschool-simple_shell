#include "simple_shell.h"

/**
 * execute_cmd - parse and execute command
 * @line: raw input line
 * @prog_name: shell name
 *
 * Return: 0
 */
int execute_cmd(char *line, char *prog_name)
{
	char **argv;
	char *path;
	pid_t pid;
	int status;

	argv = split_line(line);
	if (!argv || !argv[0])
	{
		free_argv(argv);
		return (0);
	}

	path = resolve_path(argv[0]);
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
	else
		waitpid(pid, &status, 0);

	free(path);
	free_argv(argv);
	return (0);
}
