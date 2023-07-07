#include "main.h"
#include <stdio.h>

/**
 * get_endianness - This function checks  for the
 * endianness of the system.
 *
 * Return: This function returns 0 if the system is big endian,
 * 1 if it is little endian.
 */

int get_endianness(void)
{
	unsigned int end_value = 1;

	char *ptr = (char *)&end_value;

	return (*ptr == 1);

	/* Checking  if the least significant byte is 1, it's little endian */

}
