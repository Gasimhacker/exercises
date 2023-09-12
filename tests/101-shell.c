#include "main.h"


/**
 * main - Super simple shell example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;
	size_t n = 0;
	char *buff = NULL;
	char **split;

	while (1)
	{

		printf("#cisfun$ ");
		if (getline(&buff, &n, stdin) == -1)
			break;

		split = split_string(buff, " \n");
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execv(split[0], split) == -1)
			{
				perror("Error");
				free(split);
				free(buff);
				exit(1);
			}
		}
		else
		{
			wait(&status);
			free(split);
		}
	}

	free(buff);

	return (0);
}
