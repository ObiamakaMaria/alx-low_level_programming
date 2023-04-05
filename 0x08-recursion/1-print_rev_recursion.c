#include "main.h"

/**
 * _print_rev_recursion - this function prints a string in reverse
 * @s: This is the string to be printed to the console.
 */

void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}

