#include "lists.h"

/**
 * free_listint_safe - This function frees the listint_t
 * linked list with a loop.
 * @h: pointer to the first node in the linked list.
 * Description: This  function sets the head to NULL.
 * Return: The function returns the number of elements in the freed list.
 */

size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	int data;
	listint_t *temp_node;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		data = *h - (*h)->next;
		if (data > 0)
		{
			temp_node = (*h)->next;
			free(*h);
			*h = temp_node;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}
