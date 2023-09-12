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
