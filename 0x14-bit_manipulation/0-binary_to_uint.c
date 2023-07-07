#include "main.h"
#include <stdio.h>


/*
 * unsigned int binary_to_uint: This function converts a number
 * from  binary to Decimal.
 *
 * @b: This is the binary number string
 * .
 * Return: This function returns the converted decimal number,
 * or 0 if the binary number is invalid.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal = 0; /* This is the decimal result */
	int a = 0;

	if (b == NULL)
		return (0);

	while (b[a] != '\0')
	{
		if (b[a] != '0' && b[a] != '1')
			return (0);

		/* Converting the binary to decimal */

		decimal = (decimal << 1) + (b[a] - '0');

		a++;
	}

	return (decimal);
}
