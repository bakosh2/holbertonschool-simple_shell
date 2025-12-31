#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Shell core */
int execution(char **tokens, char **env, char *prog_name);
char *find_command(char *cmd, char **env);
int die(char **tokens);

/* String helpers */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);

/* Memory */
void free_array(char **tokens);

#endif /* SIMPLE_SHELL_H */
