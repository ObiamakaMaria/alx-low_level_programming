#include "hash_tables.h"

/**
 * hash_table_delete - This function deletes hash table
 * @ht: The hashtable
 *  Return: It returns NULL.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t *ptr, *tmp;
	hash_table_t *table = ht;

	if (ht == NULL)
		return;
	for (a = 0; a < ht->size; a++)
	{
		if (ht->array[a])
		{
			ptr = ht->array[a];
			while (ptr != NULL)
			{
				tmp = ptr->next;
				free(ptr->key);
				free(ptr->value);
				free(ptr);
				ptr = tmp;
			}
		}
	}
	free(table->array);
	free(table);
}
