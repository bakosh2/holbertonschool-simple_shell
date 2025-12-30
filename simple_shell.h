#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int execute_cmd(char *line, char *prog_name);
char *resolve_path(char *cmd);
char **split_line(char *line);
void free_argv(char **argv);

#endif /* SIMPLE_SHELL_H */
