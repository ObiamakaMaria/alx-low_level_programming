#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end -s function  adds a new node at the end of a linked list
 * @head: This is a double pointer to the list_t list
 * @str:  This is the string to put in the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	new_node = malloc(sizeof(list_t)); /*allocating memmory space */
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = len;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (temp->next)
		temp = temp->next;
	temp->next = new_node;

	return (new_node);
}

