#include "main.h"

/**
 * create_args - Create the arguments list
 *
 * Return: The arguments list
 */
char **create_args(void)
{
	char *buff = NULL, **args;
	size_t n;

	if (getline(&buff, &n, stdin) == -1)
		exit(1);

	args = split_string(buff, " \n");
	free(buff);

	return (args);
}
