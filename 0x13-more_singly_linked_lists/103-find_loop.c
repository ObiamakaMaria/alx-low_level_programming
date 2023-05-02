#include "lists.h"

/**
 * find_listint_loop - This function finds the loop in the
 * listint_t linked list
 * @head: This is the pointer that points to the first
 * node in the linked list
 *
 * Return: The function returns address of the node where
 * the loop starts, or NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *node_1 = head;
	listint_t *node_2 = head;

	if (head == NULL)
		return (NULL);

	while (node_1 && node_2 && node_2->next)
	{
		node_2 = node_2->next->next;
		node_1 = node_1->next;
		if (node_2 == node_1)
		{
			node_1 = head;
			while (node_1 != node_2)
			{
				node_1 = node_1->next;
				node_2 = node_2->next;
			}
			return (node_2);
		}
	}

	return (NULL);
}

