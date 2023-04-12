#include "main.h"
#include <stdlib.h>

/**
 * create_array - This function creates an array and initializes with a
 * char data type
 * @size: This represents the size of the array
 * @c:    This is the data type to assign
 *
 * Return: This function returns a pointer if sucessful and 0 if unsucessful
 *
 */

char *create_array(unsigned int size, char c)
{

	char *str;

	unsigned int i;



	str = malloc(sizeof(char) * size);

	if (size == 0 || str == NULL)

		return (NULL);



	for (i = 0; i < size; i++)

		str[i] = c;

	return (str);

}

