#include "hash_tables.h"

/**
 * hash_table_create - Creates a new hash table.
 * @size: The size of the array.
 * Return: A pointer to the newly created hash table, or NULL on failure.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *newest_table = NULL;
	unsigned long int i;

	if (size < 1)
		return (NULL);
	newest_table = malloc(sizeof(hash_table_t));
	if (newest_table == NULL)
		return (NULL);

	newest_table->array = malloc(sizeof(hash_node_t *) * size);

	if (newest_table->array == NULL)
	{
		free(newest_table);
		return (NULL);
	}
	newest_table->size = size;

	for (i = 0; i < size; i++)
	{
		newest_table->array[i] = NULL;
	}

	return (newest_table);
}
