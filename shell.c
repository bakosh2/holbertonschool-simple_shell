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
        char *argv_exec[64];
        char *token;
        int i = 0;

        (void)prog_name;

        if (cmd == NULL || *cmd == '\0')
                return (-1);

        token = strtok(cmd, " \t");
        while (token && i < 63)
        {
                argv_exec[i++] = token;
                token = strtok(NULL, " \t");
        }
        argv_exec[i] = NULL;

        pid = fork();
        if (pid == -1)
        {
                perror("fork");
                return (-1);
        }

        if (pid == 0)
        {
                execve(argv_exec[0], argv_exec, env);
                exit(127);
        }
        else
        {
                waitpid(pid, &status, 0);
        }

        return (0);
}

