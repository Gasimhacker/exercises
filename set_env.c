#include "main.h"


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
	int offset;
	int count = 0;

	if (name == NULL || value == NULL || is_equal_found(name))
		return (-1);

	env_var = _getenv(name, &offset);
	if ((env_var && !overwrite) || (env_var && _strcmp(env_var, value) == 0))
		return (0);

	while (environ[count])
		count++;

	new_var = create_var(name, value);
	if (new_var == NULL)
		return (-1);

	if (env_var)
	{
		free(environ[offset]);
		environ[offset] = new_var;
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
	}
	return (0);
}

