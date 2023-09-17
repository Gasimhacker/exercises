#include "main.h"

/**
 * main - Super simple shell example
 *
 * Return: Always 0.
 */
int main(void)
{

	if (!isatty(STDIN_FILENO))
		run_non_interactive();
	else
		run_interactive();

	return (0);
}
