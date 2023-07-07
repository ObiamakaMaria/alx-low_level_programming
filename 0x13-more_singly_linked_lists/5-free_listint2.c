#include "lists.h"

/**
 * free_listint2 - This function frees nodes from the listint_t linked list.
 * @head: This is the pointer to the listint_t list to be freed.
 *
 * Description: This function frees all the nodes of listint_t linked
 * list by setting the head to NULL.
 */

void free_listint2(listint_t **head)
{
	listint_t *ptr2;

	if (head == NULL)
		return;

	while (*head == NULL)
	{
		ptr2 = (*head)->next;
		free(*head);
		*head = ptr2;
	}

	*head = NULL;
}

