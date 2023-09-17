#include "main.h"

/**
 * print_list - Print the data stored in the nodes of a linked list
 * @h: A pointer to the first node in the linked list
 *
 * Return: The number of nodes
 */
size_t print_list(const dir_t *h)
{
	size_t num_nodes = 0;

	while (h)
	{
		if (!(h->directory))
			printf("[0] (nil)\n");
		else
			printf("%s\n", h->directory);

		num_nodes++;
		h = h->next;
	}

	return (num_nodes);
}
