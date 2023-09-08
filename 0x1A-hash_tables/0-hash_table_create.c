#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - Creates a new hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created hash table, or NULL on failure.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table = NULL;
	unsigned long int i;

	if (size < 1)
		return (NULL);

	/* Allocating  memory for the hash table structure */
	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL)
		return (NULL);

	/* Allocating  memory for the array of hash_node_t pointers (buckets) */
	new_table->array = malloc(sizeof(hash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	/* Initialize the size of the hash table */
	new_table->size = size;

	/* Initialize all elements of the array to NULL */
	for (i = 0; i < size; i++)
	{
		new_table->array[i] = NULL;
	}

	return (new_table);
}
