#include "main.h"

/**
 * split_string - Split the string into an array of tokens
 * @str: The string to split
 * @delimiter: A string containing all the posibble delimiters
 *
 * Return: An array of splitted words
 *	   Or "NULL" on failure
 */
char **split_string(const char *str, const char *delimiter)
{
	char **words = NULL;
	char *str_copy = _strdup(str);
	char *token = strtok(str_copy, delimiter);
	int count = 1;


	words = malloc(sizeof(char *));

	if (!words)
		return (NULL);

	while (token != NULL)
	{
		words = realloc(words, (count + 1) * sizeof(char *));

		if (!words)
			return (NULL);

		words[count - 1] = _strdup(token);
		words[count] = NULL;

		count++;
		token = strtok(NULL, delimiter);
	}

	free(str_copy);

	return (words);
}
