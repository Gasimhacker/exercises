#include "main.h"


int delete_var(int count, int offset)
{
	char **new_environment, *temp_var;
	int i = 0;

	new_environment = malloc(count * sizeof(char *));
	if (new_environment == NULL)
		return (-1);

	while (i < offset)
	{
		new_environment[i] = environ[i];
		i++;
	}

	temp_var = environ[offset];

	while(environ[i])
	{
		new_environment[i] = environ[i + 1];
		i++;
	}

	free(temp_var);
	free(environ);

	environ = new_environment;
	return (0);
}

/**
 * _unsetenv - Delete a a variable from the environment variable
 * @name: The name of the variable to delete
 *
 * Return: On success - 0
 *	   On error - -1
 */
int _unsetenv(const char *name)
{
	char *env_var;
	int *alloced = is_alloced();
	int offset, count = 0;

	if (name == NULL || !is_valid(name))
		return (-1);

	env_var = _getenv(name, &offset);

	if (env_var == NULL)
		return (0);

	while (environ[count])
		count++;
	printf("count = %d, offset = %d\n", count, offset);

	if (*alloced == 0)
		copy_to_heap(count, alloced);

	delete_var(count, offset);

	return (0);
}

