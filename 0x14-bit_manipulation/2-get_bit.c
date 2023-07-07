#include "main.h"
#include <stdio.h>

/**
 * get_bit - This function retrieves the value of a bit at a given index.
 *
 * @n: This is the number from which to extract the bit.
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit at the given index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{

	unsigned long int bits_mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);

		/* This returns -1 if the index is out of range */

	}
	bits_mask = 1UL << index;

	/* Creating a mask with only the bit at the given index set */
	if ((n & bits_mask) == 0)
	{
		return (0);
		/* Returning 0 if the bit at the given index is 0 */

	}
	else
	{
		return (1);

		/* Returning 1 if the bit at the given index is 1 */
	}

}
