#include <stdio.h>
#include "main.h"

/**
 * print_binary - This function  prints the binary representation of a number.
 * @n: This is the number to print in binary.
 * Description: In this function, malloc, % or / operators are not used.
 *
 * Return: This function returns nothing.
 */

void print_binary(unsigned long int n)
{
	int y;

	int binary_count = 0;

	unsigned long int current_num;

	for (y = 63; y >= 0; y--)
{
		current_num = n >> y;

		if (current_num & 1)
		{
			_putchar('1');
			binary_count++;
		}
		else if (binary_count)
			_putchar('0');
	}
	if (!binary_count)
		_putchar('0');
}
