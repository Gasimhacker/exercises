#include <stdio.h>

/**
 * main - Check if the addresses are equal
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("%p\n", (void *)environ);
	printf("%p\n", (void *)env);

	return (0);
}
