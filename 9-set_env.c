#include "main.h"

/**
 * is_same - Check if the new value is the same as the old value
 * @old_value: The old value
 * @new_value: The new value
 *
 * Return: If the values are equal - 1
 *	   otherwise - 0
 */
int is_same(char *old_value, const char *new_value)
{
	int i = 0;

	while (new_value && (new_value[i] || old_value[i]))
	{
		if (new_value[i] != old_value[i])
			return (0);
		i++;
	}

	return (1);
}

/**
 * create_var - Create a new variable "name=value"
 * @name: The name of the variable
 * @value: The value of the variable
 *
 * Return: A pointer to the variable created
 */
char *create_var(const char *name, const char *value)
{
	char *new_var;
	int len1 = _strlen(name);
	int len2 = _strlen(value);

	new_var = malloc((len1 + len2 + 2) * sizeof(char));
	if (new_var == NULL)
		return (NULL);

	_strcpy(new_var, name);
	new_var[len1] = '=';
	_strcpy(new_var + len1 + 1, value);

	return (new_var);
}


/**
 * count_vars - Count the number of variables
 *		inside the environment variable array
 * @environ: The environment variable array
 *
 * Return: The number of variables inside the array
 */
int count_vars(char **environ)
{
	int count = 0;

	while (environ[count])
		count++;

	return (count);
}

/**
 * update_environment - Update the old environmet variable with a new
 *			environment adding the new variable
 * @old_environment: The environment that should be updated
 * @new_var: The new variable to be added
 *
 * Return: On success - A pointer to the new variable
 *	   On error - "NULL"
 */
char **update_environment(char **old_environment, char *new_var)
{
	char **new_environment;
	static int alloced;
	int count = count_vars(old_environment);
	int i;

	if (alloced)
	{
		new_environment = realloc(old_environment, ((count + 2) * sizeof(char *)));
	}
	else
	{
		alloced = 1;
		new_environment = malloc((count + 2) * sizeof(char *));
	}

	if (new_environment == NULL)
		return (NULL);

	for (i = 0; i < count; i++)
	{
		new_environment[i] = old_environment[i];
	}

	new_environment[i] = new_var;
	new_environment[i + 1] = NULL;

	return (new_environment);
}

/**
 * _setenv - Add or modify an environment variable
 * @name: The name of the variable to add or modify
 * @value: The value to assign to the variable
 * @overwrite: If the variable is present in the environment variable
 *	       and this member is not zero the variable will be updated
 *
 * Return: On success without allocation - 0
 *	   On success and there is memory allocation - 1
 *	   On error - -1
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_var, *env_var, **new_environment;
	int offset;

	env_var = _getenv(name, &offset);

	new_var = create_var(name, value);
	if (new_var == NULL)
		return (-1);

	if (env_var)
	{
		if (!overwrite)
			return (0);

		if (is_same(env_var, value))
			return (0);

		environ[offset] = new_var;
		return (0);
	}
	else
	{
		new_environment = update_environment(environ, new_var);
	}

	if (new_environment)
	{
		environ = new_environment;
		return (1);
	}

	return (-1);
}

