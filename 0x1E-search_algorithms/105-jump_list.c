#include "search_algos.h"

/**
 * jump_list - This function searches for a value in a sorted
 * list using Jump Search algorithm.
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: The value to search for
 * Return: A pointer to the first node where value is located,
 * or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t i;
	size_t step,  prev;

	if (list == NULL || size == 0)
		return (NULL);

	step = sqrt(size);
	prev = 0;

	while (list && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);

		prev = list->index;
		for (i = 0; i < step && list->next; i++)
			list = list->next;

		if (!list)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, list->index);

	while (list && prev <= list->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return (list);

		prev = list->index;
		list = list->next;
	}

	return (NULL);
}
