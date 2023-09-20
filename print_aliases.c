#include "main.h"

/**
 * print_list - Print the data stored in the nodes of a linked list
 * @h: A pointer to the first node in the linked list
 *
 * Return: The number of nodes
 */
size_t print_aliases(const alias_t *h)
{
	size_t num_nodes = 0;

	while (h)
	{
		printf("%s=%s\n", h->name, h->value);

		num_nodes++;
		h = h->next;
	}

	return (num_nodes);
}
