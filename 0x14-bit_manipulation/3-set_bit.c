#include "main.h"
#include <stdio.h>

/**
 * set_bit - This function sets the value of a bit to 1 at a given index.
 *
 * @n: Pointer to the number where the bit needs to be set.
 * @index: The index of the bit to set, starting from 0.
 *
 * Return: This function returns  1 if the operation was successful, or -1
 * if an error occurred.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bits_mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
		/* Return -1 if the index is out of range */
	}

	bits_mask = 1UL << index;
	/* Creating a mask with only the bit at the given index set*/

	*n |= bits_mask;

	return (1);
}
