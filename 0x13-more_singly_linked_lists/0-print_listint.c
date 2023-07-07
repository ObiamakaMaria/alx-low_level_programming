#include "lists.h"

/**
 * print_listint - This function prints all the elements of
 * the linked list.
 * @h: This pointer points to the head of the linked list.
 *
 * Return: This function returns the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t num_node = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		num_node++;
		h = h->next;

	}
	return (num_node);/*Returning the number of nodes */
}

