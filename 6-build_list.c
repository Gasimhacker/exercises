#include "main.h"

/**
 * build_list - Build a linked list of the PATH directories
 *
 * Return: A pointer to the head of list
 */
dir_t build_list(void)
{
	char *path = _getenv("PATH");
	char **dir;
	dir_t *head = NULL;

	dir = split_string(path, ":");

	while (*dir)
		add_node_end(&head, *dir++);

	return (head);
}
