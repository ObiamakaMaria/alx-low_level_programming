#include <stdio.h>
#include "main.h"

/**
 *  clear_bit- This function sets the value of a bit  to 0 at a given index.
 * @n: This is the pointer to the number to be changed.
 * @index: This represents the index of the bit to be changed.
 * Description: In this function,index is the index, starting from
 *  0 of the bit you want to set.
 *
 * Return: This function returns 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n); /*Clearing the bit */

	return (1);
}
