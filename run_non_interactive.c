#include "main.h"


/**
 * run_non_interactive - Execute the shell commands in
 *			 the non interactive mode
 *
 * Return: void
 */
void run_non_interactive(void)
{
	char *full_path, **args = NULL;

	args = create_args();

	if (search_builtins(args[0], args))
	{
		clean(args);
		return;
	}

	full_path = find_file(args[0]);

	if (full_path == NULL)
	{
		clean(args);
		perror("Error");
		exit(127);
	}

	execve(full_path, args, environ);
}

