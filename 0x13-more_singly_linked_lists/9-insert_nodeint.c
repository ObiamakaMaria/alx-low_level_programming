#include "lists.h"

/**
 * insert_nodeint_at_index - This function inserts a new node at a given
 * position in the listint_t linked list
 * @head: This is the pointer that points to the first data
 * in the linked list
 * @idx: This is the index of the list where the new node should be
 * added.Index starts at 0
 *
 * Return: The function returns the address of the new node if sucessful
 * or NULL if it fails.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int o;

	listint_t *ptr, *temp;

	if (head == NULL)
	{
		return (NULL);
	}

	if (idx == 0)
	{
	ptr = malloc(sizeof(listint_t));

	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr->n = n;
	ptr->next = *head;
	*head = ptr;
	return (ptr);
	}

	temp = *head;
	for (o = 0; o < idx - 1; o++)
	{
		if (temp == NULL)
		{
			return (NULL);
		}
	temp = temp->next;
	}

	if (temp == NULL)
	{
		return (NULL);
	}
	ptr = malloc(sizeof(listint_t));
	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr->n = n;
	ptr->next = temp->next;
	temp->next = ptr;

	return (ptr);
}
