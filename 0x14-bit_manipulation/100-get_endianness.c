#include "main.h"
#include <stdio.h>


/**
 * get_endianness - This function checks the endianness of a computer system.
 * Return:  This function returns 0 for big, 1 for little.
 * Descrption: In big endian system bytes are ordered from least to
 * the  most significant.
 * while in small endian bytes are ordered from most significant to the
 * least significant.
 */

int get_endianness(void)
{
	unsigned int k = 1;
	char *c = (char *) &k;

	return (*k);
