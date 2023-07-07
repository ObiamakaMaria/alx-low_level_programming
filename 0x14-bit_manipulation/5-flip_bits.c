#include "main.h"
#include <stdio.h>

/**
 * flip_bits -This function calculates the number of bits needed to
 * flip to get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: This is the number of bits needed to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int dif;
	unsigned int counter = 0;

	dif = n ^ m;

	/* Perform bitwise XOR to get the differing bits*/

	while (dif != 0)
	{
		dif &= (dif - 1);
		counter++;
	}

	return (counter);
}

