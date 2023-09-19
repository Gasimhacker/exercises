#include "main.h"

/**
 * count_digits - count the number of digits in a number
 * @num: The number to count its digits
 *
 * Return: The number of digits
 */
int count_digits(int num)
{
	int digits = 1;

	while (num / 10 > 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

/**
 * _itoa - Convert a positive integer to string
 * @num: The number to convert
 *
 * Return: A pointer to the string created, or NULL on failure
 */
char *_itoa(int num)
{
	int digits;
	char *str;

	digits = count_digits(num);

	str = malloc((digits + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);

	str[digits--] = '\0';

	for ( ; digits >= 0; digits--)
	{
		str[digits] = ((num % 10) + '0');
		num /= 10;
	}

	return (str);
}
