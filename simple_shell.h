#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> /* For strtok function */
#include <sys/types.h>
#include <sys/wait.h>

int execute_cmd(char *cmd, char *prog_name);
char *find_in_path(char *cmd);
char **split_line(char *line);
void free_argv(char **argv);

#endif /* SIMPLE_SHELL_H */
