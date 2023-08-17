#include "lists.h"

/**
 * get_dnodeint_at_index - This function returns the nth node
 * of the dlistint_t linked list.
 * @head: This is the pointer to the head of the doubly linked list.
 * @index: Index of the node to retrieve (starting from 0).
 * Return: The function returns the  nth node, or NULL if the node
 * does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int b;
    dlistint_t *current_node = head;

    for (b = 0; current_node != NULL && b < index; b++)
    {
        current_node = current_node->next;
    }

    return (current_node);
}
