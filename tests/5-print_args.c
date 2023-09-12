#include <stdio.h>


/**
 * main - Print  all the arguments, without using argc
 * @argc: The number of arguments passed
 * @argv: The arguments vector
 *
 * Return: Always 0
 */
int main(int __attribute__((unused))argc, char **argv)
{
	while (*argv)
		printf("%s\n", *argv++);
	return (0);
}
