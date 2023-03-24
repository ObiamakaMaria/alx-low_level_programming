#include "main.h"

/**
* print_diagonal -> this function prints a diagonal line
* @n: this is the integer paramarater
*/
void print_diagonal(int n)
{
	int x, i;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (x = 0; x < n; x++)
		{
			for (i = 0; i < x; i++)
				_putchar(' ');
			_putchar(92);
			_putchar('\n');
		}
	}
}
