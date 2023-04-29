#include "lists.h"

/**
 * listint_len - This function returns the number of elements
 * in the Listint_t linked lists.
 * @h: This pointer points to the head of the linked list.
 *
 * Return: This function returns the number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t num_node = 0;

	while (h != NULL)
	{
		h = h->next;
		num_node++;

	}

	return (num_node); /*Returning the number of nodes */
}

