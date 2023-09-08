#include "hash_tables.h"

/**
 * hash_table_set - This function adds element into hash table
 * @ht: The hash table
 * @key: The hash table key
 * @value: The value to keep
 * Return: 1 on success else  0.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *newest;
	unsigned long int index, i;
	char *new_value;

	if (ht == NULL || value == NULL || *key == '\0' || key == NULL)
	{
		return (0);
	}
	new_value = strdup(value);
	if (new_value == NULL)
	{
		return (0);
	}
	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = new_value;
			return (1);
		}
	}
	newest = malloc(sizeof(hash_node_t));
	if (newest == NULL)
	{
		return (0);
	}
	newest->key = strdup(key);
	if (newest->key == NULL)
	{
		free(newest);
		return (0);
	}
	newest->value = new_value;
	newest->next = ht->array[index];
	ht->array[index] = newest;
	return (1);
}
