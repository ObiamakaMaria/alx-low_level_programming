#include "hash_tables.h"

/**
 * key_index - This function gets index of a key in a hash table
 * @key: The key to convert
 * @size: The size of the table
 * * Return: The index gotten
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
		return (hash_djb2(key) % size);
}
