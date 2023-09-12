#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int __attribute__((unused))argc, char *argv[], char *envp[])
{

    printf("Before execve\n");
    if (execve(argv[1], argv, envp) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}
