#include <stdio.h>
#include "lists.h"
#include <stdlib.h>


/**
 * print_list - This function prints all the elements of a linked list
 * @h: This represents the pointer to the list_t list. It helps us
 * to transverse through the lenght of the linked list.
 *
 * Return: the number of nodes printed
 */

size_t print_list(const list_t *h)
{
	size_t count = 0; /*initializing count to 0 */

	while (h)
	{
	if (!h->str)
		printf("[0] (nil)\n");
	else
							/* Printing the string */
	printf("[%u] %s\n", h->len, h->str);
	h = h->next;
	count++;
	}

	return (count);
}
