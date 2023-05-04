#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - This function converts a binary
 * number to  an unsigned int
 * @b: This is the string containing the binary number.
 * Description: In this function, b is pointing to a string of 0 and 1 chars.
 *
 * Return: This function returns the converted number.
 */

unsigned int binary_to_uint(const char *b)
{
	int z;

	unsigned int converted_num = 0;

	if (b == NULL)
		return (0);

	for (z = 0; b[z]; z++)
	{
		if (b[z] < '0' || b[z] > '1')
			return (0);
		converted_num = 2 * converted_num + (b[z] - '0');
	}

	return (converted_num);/*Returning the xonverted number*/
}
