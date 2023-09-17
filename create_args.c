#include "main.h"

/**
 * create_args - Create the arguments list
 * @buff: This member will store the input written by user
 * @args: After execution this member should contain
 *	  the array of arguments that will be passed to the execve
 *
 * Return: The arguments list
 */
char **create_args(char *buff, char **args)
{
	size_t n;
	if (getline(&buff, &n, stdin) == -1)
		exit(1);

	args = split_string(buff, " \n");

	return (args);
}
