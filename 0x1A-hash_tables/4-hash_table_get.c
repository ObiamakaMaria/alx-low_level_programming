#include "hash_tables.h"

/**
 * hash_table_get - This function retrieves a value associated
 * with a key in a hash table.
 * @ht: The hash table
 * @key: The key
 * Return: Thee value else, Null
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *element;

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
	{
		return (NULL);
	}
	element = ht->array[index];
	while (element && strcmp(element->key, key) != 0)
	{
		element = element->next;
	}
	if (element == NULL)
	{
		return (NULL);
	}
	return (element->value);
}
