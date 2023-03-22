#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - this function prints natural numbers numbers
 *
 * @n : this is the function parameter
 *
 * Return: alwyas 0
 */

void print_to_98(int n)
{
	if (n >= 98)
	{
		while (n > 98)
			printf("%d, ", n--);
		printf("%d\n", n);
	}
	else
	{
		while (n < 98)
			printf("%d, ", n++);
		printf("%d\n", n);
	}
}
