#include "lists.h"

/**
 * add_dnodeint - This function adds a new node at the
 * beginning of  the dlistint_t list.
 * @head: This is the pointer to a pointer to the head of the
 * doubly linked list.
 * @n: Value to be assigned to the new node.
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node1 = malloc(sizeof(dlistint_t));

	if (new_node1 == NULL)
		return (NULL);

	new_node1->n = n;
	new_node1->prev = NULL;
	new_node1->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node1;

	*head = new_node1;

	return (new_node1);
}
