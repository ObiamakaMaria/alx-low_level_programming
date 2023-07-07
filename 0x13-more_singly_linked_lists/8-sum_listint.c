#include "lists.h"

/**
 * sum_listint - This function returns the sum of all the data in the
 * listint_t linked list.
 * @head: This is the pointer that points to the first data in the linked list
 *
 * Return: The function returns 0 if the linked list is empty.
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current_node = head;

	while (current_node != NULL)
	{
		sum += current_node->n;
		current_node = current_node->next;

	}

	return (sum);
}
