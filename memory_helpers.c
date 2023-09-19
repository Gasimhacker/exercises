#include "main.h"

/**
 * get_exit_status - Save the last exit code
 *
 * Return: A pointer to the last saved exit code
 */
int *get_exit_status(void)
{
	static int exit_status = EXIT_SUCCESS;

	return (&exit_status);
}



/**
 * copy_to_heap - Copy the environment variable array to the heap
 *
 * Return: On success - 1
 *	   On error - 0
 */
int copy_to_heap(void)
{
	char **new_environment;
	int i = 0;

	while (environ[i])
		i++;

	new_environment = malloc((i + 1) * sizeof(char *));
	if (new_environment == NULL)
		return (0);

	for (i = 0; environ[i]; i++)
		new_environment[i] = _strdup(environ[i]);

	new_environment[i] = NULL;

	environ = new_environment;

	return (1);
}

/**
 * clean - Free an array of pointers
 * @array: The array to be freed
 *
 * Return: void
 */
void clean(char **array)
{
	int i;

	if (array == NULL)
		return;

	for (i = 0; array[i]; i++)
		free(array[i]);

	free(array);
}
