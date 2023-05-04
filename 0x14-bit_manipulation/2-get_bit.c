#include <stdio.h>
#include "main.h"

/**
 * get_bit- This function returns the value of a bit at a given index.
 * @n: This represents the number to search for.
 * @index: This represents the index of the bits.
 * Description: In this function,index is the index, starting from 0
 * of the bit you want to get.
 *
 * Return: This function returns the value of the bit at index index or
 * -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int value_bit;


	if (index > 63)
		return (-1);

	value_bit = (n >> index) & 1;

	return (value_bit);/*This functions returns the number of bits*/
}
