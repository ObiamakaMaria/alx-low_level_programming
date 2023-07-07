#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all -This function returns the sum of all its paramters.
 * @n: The represents the  number of paramters passed to the function.
 * @...: This ellipsis means that the function accepts a variable
 * number of arguments.
 *
 * Return: return 0  If n == 0 Otherwise - the sum of all parameters.
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum = 0;


	va_start(ap, n); /*initializes a variable argument list*/


	for (i = 0; i < n; i++)
		sum += va_arg(ap, int);


	va_end(ap);


	return (sum);
}


