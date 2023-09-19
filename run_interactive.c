#include "main.h"

/**
 * run_interactive - Execute the shell commands in the interactive mode
 *
 * Return: void
 */
void run_interactive(void)
{
	char **args, *full_path;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		args = create_args();

		if (search_builtins(args[0], args))
		{
			clean(args);
			continue;
		}

		full_path = find_file(args[0]);

		if (full_path == NULL)
		{
			clean(args);
			perror("Error");
			continue;
		}

		execute(args, full_path);
	}

}


