#include "hash_tables.h"

/**
 * hash_table_print - print key value pair in hash tables
 * @ht: the hash table
 * Return: null
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *element;
	unsigned char flag = 0;
	unsigned long int b;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	for (b = 0; b < ht->size; b++)
	{
		if (ht->array[b])
		{
			if (flag == 1)
			{
				printf(", ");
			}
			element = ht->array[b];
			while (element != NULL)
			{
				printf("%s: %s", element->key, element->value);
				element = element->next;
				if (element != NULL)
					printf(", ");
			}
			flag = 1;
		}
	}
	printf("}\n");
}
