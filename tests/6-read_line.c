#include <stdio.h>

/**
 * main - Print the user command on the screen
 *
 * Return: On sucess - 0
 *	   On failure - -1
 */
int main(void)
{
	char *buff = NULL;
	size_t n = 0;

	printf("$ ");
	if (getline(&buff, &n, stdin) == -1)
		return (-1);

	printf("%s", buff);

	return (0);
}
