#include "lists.h"

/**
 * free_listint - This function  frees the nodes in the
 * listint_t linked list
 *
 * @head: This is the pointer to the head of the listint_t list to be freed
 * Description: This function frees all the nodes in the listint_t linked
 * list by setting the first node to NULL
 */

void free_listint(listint_t *head)
{
	listint_t *ptr;

	while (head != NULL)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}

