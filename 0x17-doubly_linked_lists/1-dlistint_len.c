#include "lists.h"

/**
 * dlistint_len - This function returns the number of elements
 * in a dlistint_t list.
 * @h: This is the  pointer to the head of the doubly linked list.
 * Return: This function returns number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t counter = 0;

	while (h != NULL)
	{
		counter++;
		h = h->next;
	}

	return (counter);
}
