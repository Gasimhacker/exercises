#include "main.h"

/**
 * execute - Execute the passed command
 * @args: The arguments passed to the command
 * @program_path: The path to the program to be executed
 *
 * Return: On success - 0
 *	   On error - 1
 */
int execute(char **args, char *program_path)
{
	int status;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(program_path, args, environ) == -1)
		{
			perror("Error");
			free(args);
		}
	}
	else
	{
		wait(&status);
		free(program_path);
	}
	return (0);
}
