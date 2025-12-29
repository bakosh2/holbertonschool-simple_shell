#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute_cmd(char *cmd, char *prog_name, char **env);

#endif /* SIMPLE_SHELL_H */
