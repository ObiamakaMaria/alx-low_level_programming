#include "lists.h"

/**
 * sum_dlistint - This function returns the sum of all the data (n) in
 * a dlistint_t linked list.
 *
 * @head: This is the pointer to the head of the doubly linked list.
 * Return: The sum of all the data, or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum_data = 0;

	while (head != NULL)
	{
		sum_data += head->n;
		head = head->next;
	}

	return (sum_data);
}
