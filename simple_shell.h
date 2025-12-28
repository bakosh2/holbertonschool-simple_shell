#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int _exec_cmd(char *cmd, char *prog_name, char **env); /* shell.c */
int main(int argc, char **argv, char **env); /* main.c */

#endif /* SIMPLE_SHELL_H */
