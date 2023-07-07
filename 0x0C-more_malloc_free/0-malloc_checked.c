#include <stdlib.h>
#include "main.h"

/**
 * *malloc_checked - This function allocates memory using malloc
 * @b: This represents the number of bytes to allocated
 *
 * Return: This function returns a pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)

{

	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);/*returning a pointer*/
}

