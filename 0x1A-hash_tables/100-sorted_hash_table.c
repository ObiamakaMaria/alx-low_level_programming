#include "hash_tables.h"

/**
 * shash_table_create - This function creates a sorted hash table.
 * @size: The size of the hash table.
 *
 * Return: A pointer to the newly created sorted hash table, or NULL on failure.
 *      */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;
	unsigned long int i;

	if (size < 1)
		return (NULL);

	new_table = malloc(sizeof(shash_table_t));
	if (new_table == NULL)
		return (NULL);

	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	new_table->size = size;
	new_table->shead = NULL;
	new_table->stail = NULL;

	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

	return (new_table);
}

/**
 * shash_table_set -This function  inserts key-value pairs
 * into the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key to insert.
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		if (ht->shead != NULL)
			ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		current = ht->shead;
		while (current->snext != NULL && strcmp(key, current->snext->key) > 0)
			current = current->snext;
		new_node->sprev = current;
		new_node->snext = current->snext;
		if (current->snext != NULL)
			current->snext->sprev = new_node;
		current->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - This function retrieve values by key from
 * the sorted hash table.
 *  @ht: The sorted hash table.
 *  @key: The key to search for.
 *
 *  Return: The value associated with the key, or NULL if the key is not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Thus function prints the sorted hash
 * table in ascending order.
 * @ht: The sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	int first = 1;

	if (ht == NULL)
		return;

	current = ht->shead;
	printf("{");
	while (current != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		first = 0;
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - this function prints the sorted hash
 * table in descending order.
 * @ht: The sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	int first = 1;

	if (ht == NULL)
		return;

	current = ht->stail;
	printf("{");
	while (current != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		first = 0;
		current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - This function dDelete the sorted hash table
 * and free memory.
 * @ht: The sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current, *temp;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}

	free(ht->array);
	free(ht);
}
