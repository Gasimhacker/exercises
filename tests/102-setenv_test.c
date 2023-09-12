#include "main.h"

/**
 * main - Check the _setenv function
 *
 * Return: always 0
 */
int main(void)
{
	int i = 0, status;

	status = _setenv("HELLO", "WORLD", 1);

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	if (status == 1)
		free(environ);

	return (0);

}
