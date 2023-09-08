#include "lists.h"

/**
 * free_dlistint - This function frees the dlistint_t list.
 * @head:  This is a Pointer to the head of the doubly linked list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next;
		free(current_node);
	}
}
