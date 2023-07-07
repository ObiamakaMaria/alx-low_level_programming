#include <stdlib.h>
#include "lists.h"

/**
 * free_list - This function frees a linked list
 * @head: This is the list_t list to be freed
 */

void free_list(list_t *head)
{
	list_t *tem;

	while (head != NULL)
	{
		tem = head->next;
		free(head->str);
		free(head);
		head = tem;
	}
}

