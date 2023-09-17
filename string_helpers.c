#include "main.h"

/**
 * _strlen - Returns the length of the string
 * @s: The string to calculate its length
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);

}

/**
 * _strdup - Copy a string given as a parameter into
 *		  a newly allocated memory space
 * @str: The string to be copied
 *
 * Return: A pointer to the duplicated string, NULL otherwise
 */
char *_strdup(const char *str)
{
	unsigned int i;
	unsigned int len;
	char *p;

	if (str == NULL)
		return (0);

	len = _strlen(str);

	p = malloc((len + 1) * sizeof(char));

	if (p == 0)
		return (p);

	for (i = 0; i <= len; i++)
		*(p + i) = *(str + i);

	return (p);
}

/**
 * _strcpy - Copy a string in one variable into another variable
 * @src: The string to be copied
 * @dest: The destination of the copied string
 *
 * Return: The pointer to the destination.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The string to compare with the first
 * Return: Zero if both strings are identical,
 *	   greater than zero when the matching
 *	   character of left string has greater
 *	   ASCII value than the character of
 *	   the right string, less than zero
 *	   when the left character has a smaller
 *	   value.
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1) == (*s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
