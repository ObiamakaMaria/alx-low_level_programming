#include "lists.h"

/**
 * delete_nodeint_at_index - This function deletes the node at the index
 * of the listint_t linked list.
 * @head: This is the pointer that points to the first node in the linked list
 * @index: This represents the index of the node that should be deleted.
 * Index starts at 0
 * Return: The function returns 1 if sucessful and -1 if it fails.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp_node = *head;

	listint_t *current_node = NULL;

	unsigned int b = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp_node);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temp_node || !(temp_node->next))
			return (-1);
		temp_node = temp_node->next;
		i++;
	}


	current_node = temp_node->next;
	temp_node->next = current_node->next;
	free(current_node);
	return (1);
}
