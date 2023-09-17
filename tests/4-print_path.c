#include "main.h"

/**
 * main - Print each directory contained in the environment variable PATH
 *
 * Return: Always 0
 */
int main(void)
{
	char *path = _getenv("PATH");
	char **dir;
	int i = 0;

	dir = split_string(path, ":");

	while (dir[i])
		printf("%s\n", dir[i++]);

	free_tokens(dir);

	return (0);
}
