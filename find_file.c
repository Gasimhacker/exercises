#include "main.h"

/**
 * create_path - Create an absolute path
 * @path: The path to file
 * @file_name: The file name
 *
 * Return: The created absolute path
 */
char *create_path(char *path, char *file_name)
{
	int len1 = _strlen(path);
	int len2 = _strlen(file_name);
	char *new_var;

	new_var = malloc((len1 + len2 + 2) * sizeof(char));
	_strcpy(new_var, path);
	_strcpy(new_var + len1, "/");
	_strcpy(new_var + len1 + 1, file_name);

	return (new_var);
}

/**
 * find_file - check if the file is present
 * @file_name: The file name
 *
 * Return: If the file is found - a pointer to the full path
 *	   Otherwise - NULL
 */
char *find_file(char *file_name)
{
	int i = 0, offset;
	struct stat st;
	char *path = _getenv("PATH", &offset);
	char **dir;
	char *full_path;

	if (file_name == NULL)
		return (NULL);

	if (stat(file_name, &st) == 0)
	{
		full_path = _strdup(file_name);
		return (full_path);
	}

	dir = split_string(path, ":");

	while (dir[i])
	{
		full_path = create_path(dir[i], file_name);
		if (stat(full_path, &st) == 0)
		{
			clean(dir);
			return (full_path);
		}
		else
		{
			free(full_path);
			i++;
		}
	}

	clean(dir);

	return (NULL);
}
