#include "simple_shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void shell_loop(void)
{
	char *line = NULL;
	size_t len = 0;

	while (getline(&line, &len, stdin) != -1)
	{
		if (line[0] == '\n')
			continue;
		system(line);
	}
	free(line);
}

