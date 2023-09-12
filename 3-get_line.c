#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	FILE *file;
	char *new_lineptr;
	char ch;

	if (lineptr == NULL || n == NULL || fp == NULL)
		return (-1);

	file = fopen(stream, "r");

	if (!file)
		return (-1);

	if (*linept == NULL || *n == 0)
	{
		*n = 120;
		new_lineptr = realloc(*lineptr, *n);

		if (!new_lineptr)
			return (-1);
		*line_ptr = new_lineptr;
	}

	while (1)
	{
		ch = getc(file);
		if (ch == EOF || interrupt == 1)
			result = (-1);
	}

}
