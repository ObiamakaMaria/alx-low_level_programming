#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name -  This function prints a  name using pointer to function
 * @name:  This is the string to add
 * @f: pointer to function
 * Return: nothing
 **/

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	return;
	f(name);
}

