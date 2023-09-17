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

	while (new_value[i] || old_value[i])
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
	int len1 = _strlen(name);
	int len2 = _strlen(value);
	char *new_var;

	new_var = malloc((len1 + len2 + 2) * sizeof(char));
	_strcpy(new_var, name);
	_strcpy(new_var + len1, "=");
	_strcpy(new_var + len1 + 1, value);

	return (new_var);
}

/**
 * _setenv - Add or modify an environment variable
 * @name: The name of the variable to add or modify
 * @value: The value to assign to the variable
 * @overwrite: If the variable is present in the environment variable
 *	       and this member is not zero the variable will be updated
 *
 * Return: On success - 0
 *	   On error - -1
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_var, *env_var, **new_environment = NULL;
	int *alloced = is_alloced(), offset;
	int count = 0;

	if (name == NULL || value == NULL || !is_valid(name))
		return (-1);

	env_var = _getenv(name, &offset);
	if ((env_var && !overwrite) || (env_var && is_same(env_var, value)))
		return (0);

	while (environ[count])
		count++;
	if (*alloced == 0)
		copy_to_heap(count, alloced);

	new_var = create_var(name, value);
	if (new_var == NULL)
		return (-1);

	if (env_var)
	{
		free(environ[offset]);
		environ[offset] = new_var;
		return (0);
	}
	else
	{
		new_environment = realloc(environ, ((count + 2) * sizeof(char *)));
		if (new_environment == NULL)
		{
			free(new_var);
			return (-1);
		}
		new_environment[count] = new_var;
		new_environment[count + 1] = NULL;
		environ = new_environment;
		return (0);
	}
	return (0);
}

