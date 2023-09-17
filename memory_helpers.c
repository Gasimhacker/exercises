#include "main.h"

/**
 * is_alloced - Check  if the environment variable is alloced
 *
 * Return: The address of the static variable to
 *	   be able to change it to 1 if an allocation is made
 */
int *is_alloced(void)
{
	static int alloced;

	return (&alloced);
}


/**
 * copy_to_heap - Copy the environment variable array to the heap
 * @count: The number of elements in the stack environment
 * @alloced: This member should be changed to 1 after the allocation
 *
 * Return: On success - 1
 *	   On error - 0
 */
int copy_to_heap(int count, int *alloced)
{
	char **new_environment;
	int i = 0;

	new_environment = malloc((count + 1) * sizeof(char *));
	if (new_environment == NULL)
		return (0);

	for (i = 0; environ[i]; i++)
		new_environment[i] = _strdup(environ[i]);

	new_environment[i] = NULL;

	*alloced = 1;

	environ = new_environment;

	return (1);
}

/**
 * clean - Free the allocations created by [un]setenv
 *
 * Return: void
 */
void clean(void)
{
	int i = 0;

	while (environ[i])
			free(environ[i++]);

	free(environ);

}

/**
 * free_tokens - Free an array of tokens
 * @token: The array to be freed
 *
 * Return: void
 */
void free_tokens(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}
