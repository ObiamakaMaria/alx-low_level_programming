#include "lists.h"

/**
 * pop_listint - This function deletes the head node of the
 * listint_t linked list
 * @head: This is the pointer that points to the first data in the linked list
 *
 * Return: The function returns the data inside the node that was deleted,
 * or 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *ptr;
	int z;

	if (!head || !*head)
		return (0);

	z = (*head)->n;
	ptr = (*head)->next;
	free(*head);
	*head = ptr;

	return (z);
}

