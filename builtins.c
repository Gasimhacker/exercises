#include "main.h"


int create_alias(char *alias)
{
	int i = 0;
	alias_t *head = get_head();
	char **name_val_arr = split_string(alias, "=");

	while (name_val_arr[i])
		i++;

	if (i != 2)
	{
		clean(name_val_arr);
		return (-1);
	}

	add_alias_end(&head, name_val_arr[0], name_val_arr[1]);
	clean(name_val_arr);

	return (1);
}	



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
	int *exit_status = get_exit_status();
	static alias_t *head = get_head();

	while (args[i])
		i++;

	if (_strcmp(cmd_name, "exit") == 0)
	{
		if (i > 2)
			return  (-1);
		if (i == 2)
			*exit_status = _atoi(args[1]);

		clean(args);
		clean(environ);
		exit(*exit_status);
	}
	else if (_strcmp(cmd_name, "env") == 0)
	{
		print_env();
	}
	else if (_strcmp(cmd_name, "setenv") == 0)
	{
		if (i != 3)
			return  (-1);
		_setenv(args[1], args[2], 1);
	}
	else if (_strcmp(cmd_name, "unsetenv") == 0)
	{
		if (i != 2)
			return  (-1);
		_unsetenv(args[1]);
	}
	else if (_strcmp(cmd_name, "alias") == 0)
	{
		if (i == 1)
			print_aliases(head);
		else if (i > 1)
		{
			create_alias(args[1]);
		}
	}
	else
	{
		return (0);
	}

	return (1);
}
