#include "main.h"

/**
 * add_node_end - Add a new node at the end of a linked list
 * @head: A pointer to a pointer to the first node in the linked list
 * @str: The string to put inside the node
 *
 * Return: A pointer to the new node in the linked list
 */
dir_t *add_node_end(dir_t **head, const char *str)
{
	dir_t *new;
	dir_t *tail = *head;

	new = malloc(sizeof(dir_t));

	if (!new)
		return (NULL);

	new->directory = strdup(str);

	if (!(new->directory))
	{
		free(new);
		return (NULL);
	}

	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	while (tail->next)
		tail = tail->next;

	tail->next = new;

	return (new);
}
