#include "main.h"

/**
 * print_env print the current environment
 *
 * Return: void
 */
void print_env(void)
{
	int i = 0;

	while (environ && environ[i])
		printf("%s\n", environ[i++]);
}
