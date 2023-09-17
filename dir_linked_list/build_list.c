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
	int i;

	dir = split_string(path, ":");

	while (dir[i])
		add_node_end(&head, dir[i++]);

	free_tokens(dir);

	return (head);
}
