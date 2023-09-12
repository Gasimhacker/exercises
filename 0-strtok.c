#include <stdio.h>

/**
 * increment_pointer - Increment the Pointer until a non delimiter
 *		       character is reached
 * @ptr: The pointer to increment
 * @delim: The delimiter string
 *
 * Return: A pointer to the first non delimiter character
 */
char *increment_pointer(char *ptr, char *delim)
{
	int i = 0;

	while (delim && delim[i])
	{
		if (delim[i] == *ptr)
		{
			ptr++;
			i = 0;
			continue;
		}

		i++;
	}

	return (ptr);
}


/**
 * _strtok - Split the string into tokens
 * @str: The string to split
 * @delim: The string containing delimiters that
 *	   indicate an end of a word(token)
 *
 * Return: A pointer to the next token everytime it is called
 *	   On failure - NULL
 */
char *_strtok(char *str, char *delim)
{
	static char *start;
	int i = 0, j = 0;

	if (str != NULL)
		start = increment_pointer(str, delim);

	if (start == NULL)
		return (NULL);



	while (start[i])
	{
		if (start[i] == delim[j++])
		{
			start[i] = '\0';
			str = start;
			start = increment_pointer(start + i + 1, delim);
			return (str);
		}

		if (!delim[j])
		{
			j = 0;
			i++;
		}
	}

	str = start;
	start = NULL;

	return (str);
}
