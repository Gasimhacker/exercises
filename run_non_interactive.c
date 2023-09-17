#include "main.h"


/**
 * run_non_interactive - Execute the shell commands in
 *			 the non interactive mode
 *
 * Return: void
 */
void run_non_interactive(void)
{
	char *buff = NULL, *full_path, **args = NULL;

	args = create_args(buff, args);

	if (search_builtins(args[0], args))
	{
		free_tokens(args);
		return;
	}

	full_path = find_file(args[0]);

	if (full_path == NULL)
	{
		free_tokens(args);
		free(buff);
		perror("Error");
		exit(127);
	}

	execve(full_path, args, environ);
}

