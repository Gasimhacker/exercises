#include "main.h"

/**
 * run_interactive - Execute the shell commands in the interactive mode
 *
 * Return: void
 */
void run_interactive(void)
{
	char **args, *full_path, *buff = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		args = create_args(buff, args);

		if (search_builtins(args[0], args))
		{
			free_tokens(args);
			continue;
		}

		full_path = find_file(args[0]);

		if (full_path == NULL)
		{
			free_tokens(args);
			perror("Error");
			continue;
		}

		execute(args, full_path);
		free_tokens(args);
	}

	free(buff);
}


