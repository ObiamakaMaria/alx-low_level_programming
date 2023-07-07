#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - This function will help to count the
 * number of unique nodes in the looped listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The function returns thenumber of nodes in
 * the listint_t linked list
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tito, *hary;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tito = head->next;
	hary = (head->next)->next;

	while (hary)
	{
		if (tito == hary)
		{
			tito = head;
			while (tito != hary)
			{
				nodes++;
				tito = tito->next;
				hary = hary->next;
			}

			tito = tito->next;
			while (tito != hary)
			{
				nodes++;
				tito = tito->next;
			}

			return (nodes);
		}

		tito = tito->next;
		hary = (hary->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe -This function prints all the data in the
 * listint_t list.
 * @head: A pointer to the head of the listint_t linked  list.
 *
 * Return: The function returns the number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}

