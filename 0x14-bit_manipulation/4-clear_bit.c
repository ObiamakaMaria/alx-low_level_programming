#include "main.h"
#include <stdio.h>

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number where the bit needs to be cleared.
 * @index: The index of the bit to clear, starting from 0.
 * Return: 1 if the operation was successful, or -1 if an error occurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bits_mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
		/* Returning -1 if the index is out of range */

	}
	bits_mask = ~(1UL << index);

	*n &= bits_mask;

	return (1);
}
