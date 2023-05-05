#include <stdio.h>
#include "main.h"

/**
 *  flip_bits- This function returns the number of bits you would
 *  need to flip to get from one number to another.
 * @n: This represents the first the number to be filpped.
 * @m: This represents the second number to be filpped.
 *
 * Description: In this function,the % or / operators are not allowed.
 * Return: This function the number of bits changed.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, count_bits = 0;
	unsigned long int current_bits;
	unsigned long int exclusive_xor = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		current_bits = exclusive_xor >> x;
		if (current_bits & 1)
			count_bits++;
	}

	return (count_bits);
}

