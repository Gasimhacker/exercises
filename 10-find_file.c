#include "main.h"

/**
 * find_file - check if the file is in the current path
 * @path: The path of the file
 * @file: The file name
 *
 * Return: If the file is found - 1
 *	   Otherwise - 0
 */
int find_file(char *path, char *file)
{
	struct stat st;
	int len1 = strlen(path);
	int len2 = strlen(file);
	char full_path[len1 + len2];

	if (!path && !file)
		return (0);

	strcpy(full_path, path);
	strcpy(full_path + len1, file);

	if (stat(full_path, &st) == 0)
		return (1);

	return (0);
}
