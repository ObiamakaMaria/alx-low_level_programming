#include "lists.h"

/**
 * delete_dnodeint_at_index - This function deletes the node at a given
 * index in a dlistint_t list.
 * @head: This is the pointer to a pointer to the head of the
 * doubly linked list.
 * @index: Index of the node to be deleted.
 * Return: This function returns 1 if it succeeded, -1 if it failed.
 *
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *he1;
	dlistint_t *he2;
	unsigned int z;

	he1 = *head;

	if (he1 != NULL)
		while (he1->prev != NULL)
			he1 = he1->prev;

	z = 0;

	while (he1 != NULL)
	{
		if (z == index)
		{
			if (z == 0)
			{
				*head = he1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				he2->next = he1->next;

				if (he1->next != NULL)
					he1->next->prev = he2;
			}

			free(he1);
			return (1);
		}
		he2 = he1;
		he1 = he1->next;
		z++;
	}

	return (-1);
}
