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

    if (cmd == NULL || *cmd == '\0')
        return (-1);

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (-1);
    }

    if (pid == 0) /* child process */
    {
        execve(cmd, NULL, env);
        /* If execve fails */
        exit(127);
    }
    else /* parent process */
    {
        waitpid(pid, &status, 0);
    }

    return (0);
}
