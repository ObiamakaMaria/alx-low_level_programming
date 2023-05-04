#include <stdio.h>
#include "main.h"

/**
 *  set_bit- This function sets the value of a bit at a given index.
 * @n: This is the pointer to the number to be changed.
 * @index: This represents the index of the bit to be set to 1.
 * Description: In this function,index is the index, starting from
 *  0 of the bit you want to set.
 *
 * Return: This function returns 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);


	*n |= (1UL << index);
	return (1);
}

