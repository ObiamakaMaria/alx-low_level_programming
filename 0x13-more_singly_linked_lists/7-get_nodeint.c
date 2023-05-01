#include "lists.h"

/**
 * *get_nodeint_at_index - This function returns the nth node of the
 * listint_t linked list
 * @head: This is the pointer that points to the first data in the linked list
 *
 * Return: The function returns NULL if the node does not exist.
 * @index: In this function, index is the index of the node
 * and it starts at 0
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
		listint_t *new_node;
		unsigned int y;

		if (head == NULL)
		{
			return (NULL);
		}

		new_node = head;
		for (y = 0; y < index; y++)
		{
		if (new_node->next == NULL)
		{
			return (NULL);

		}
			new_node = new_node->next;
		}

		return (new_node);
}
