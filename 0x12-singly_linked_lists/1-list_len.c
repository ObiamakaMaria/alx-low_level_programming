#include <stdlib.h>
#include "lists.h"

/**
 * list_len - This function returns the number of elements in a linked list
 * @h: This represents the pointer to the list_t list. It helps us
 * to transverse through the lenght of the linked list
 *
 * Return: number of elements in h
 */

size_t list_len(const list_t *h)
{
	size_t count = 0; /*initializing count to 0 */

	while (h != NULL)
	{
	count++;
	h = h->next;
	}
	return (count);
}
