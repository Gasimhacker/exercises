/**
 * is_valid - Check if the variable name passed to [un]setenv() is a valid name
 * @name: The name of the variable passed to setenv
 *
 * Return: If the name is valid - 1
 *	   otherwise - 0
 */
int is_valid(const char *name)
{
	int i = 0;

	while (name[i])
		if (name[i++] == '=')
			return (0);
	return (1);
}
