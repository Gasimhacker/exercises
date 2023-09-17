#include "main.h"

/**
 * main - Check the _setenv function
 *
 * Return: always 0
 */
int main(void)
{
	int i = 0;

	_setenv("HELLO", "WORLD", 1);
	_unsetenv("HELLO");

	while (environ[i])
		printf("%s\n", environ[i++]);
	clean();

	return (0);

}
