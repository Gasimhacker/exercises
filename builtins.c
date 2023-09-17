#include "main.h"


/**
 * search_builtins - Check if the command passed is a builtin
 *		     and if it is a builtin execute it
 * @cmd_name: The name of the command
 * @args: The arguments list to pass to the handler functions
 *
 * Return: If builtin found - 1
 *	   Otherwise - 0
 */
int search_builtins(char *cmd_name, char **args)
{
	int i = 0;

	while (args[i])
		i++;

	if (_strcmp(cmd_name, "env") == 0)
	{
		print_env();
	}
	else if (_strcmp(cmd_name, "setenv") == 0)
	{
		if (i != 3)
			return  (-1);
		setenv(args[1], args[2], 1);
	}
	else if (_strcmp(cmd_name, "unsetenv") == 0)
	{
		if (i != 2)
			return  (-1);
		unsetenv(args[1]);
	}
	else
	{
		return (0);
	}

	return (1);
}