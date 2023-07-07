#include "main.h"
#include <stdio.h>


/**
 * print_binary - This function  prints the binary representation of a number.
 * @n: This is the number to print in binary.
 *
 * Description: This function prints the binary representation of a given
 * number It does not use arrays, malloc, or the % or / operators. Also,
 * binary representation is printed using putchar.
 */

void print_binary(unsigned long int n)
{
	unsigned long int bit_mask;
	int bits_count, first_zeroes;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	bit_mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	/* Create a bitmask with the most significant bit set */

	bits_count = sizeof(unsigned long int) * 8;

	first_zeroes = 1;

	while (bits_count > 0)
	{
		if ((n & bit_mask) != 0)
			first_zeroes = 0;

		if (!first_zeroes)
		{
			if ((n & bit_mask) == 0)
				putchar('0'); /* Print '0' if the corresponding bit is 0 */
			else
				putchar('1'); /* Print '1' if the corresponding bit is 1 */
		}

		bit_mask >>= 1; /* Shift the bitmask right by 1 bit */
		bits_count--;
	}
}
