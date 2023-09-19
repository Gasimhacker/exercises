#include "main.h"

/**
 * delete_var - Delete a variable from the environment
 * @offset: The variable's offset
 *
 * Return: On success - 0
 *	   on error - -1
 */
int delete_var(int offset)
{
	char **new_environment, *temp_var;
	int i = 0, count = 0;

	while (environ[count])
		count++;

	new_environment = malloc(count * sizeof(char *));
	if (new_environment == NULL)
		return (-1);

	while (i < offset)
	{
		new_environment[i] = environ[i];
		i++;
	}

	temp_var = environ[offset];

	while (environ[i])
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
	int offset;

	if (name == NULL || is_equal_found(name))
		return (-1);

	env_var = _getenv(name, &offset);

	if (env_var == NULL)
		return (0);


	delete_var(offset);

	return (0);
}

