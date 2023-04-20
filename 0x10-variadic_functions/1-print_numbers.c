#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - This function prints numbers, followed by a new line.
 * @separator: This is the  string to be printed between numbers.
 * @n: This represents the number of integers passed to the function.
 * @...: This is an ellipsis which indicates taht the function accepts
 * a variable number of arguments.
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list nums;
	unsigned int index;


	va_start(nums, n);


	for (index = 0; index < n; index++)
	{
		printf("%d", va_arg(nums, int));


	if (index != (n - 1) && separator != NULL)
		printf("%s", separator);
	}


	printf("\n");


	va_end(nums);
}

