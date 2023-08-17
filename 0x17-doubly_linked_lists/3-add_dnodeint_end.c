#include "lists.h"

/**
 * add_dnodeint_end -  This function adds a new node at the end
 * of the dlistint_t list
 *
 * @head: This is the pointer to a pointer to the head of the doubly
 * linked list.
 * @n:  Value to be assigned to the new node.
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *new_nd;

	new_nd = malloc(sizeof(dlistint_t));
	if (new_nd == NULL)
		return (NULL);

	new_nd->n = n;
	new_nd->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = new_nd;
	}
	else
	{
		*head = new_nd;
	}

	new_nd->prev = h;

	return (new_nd);
}
