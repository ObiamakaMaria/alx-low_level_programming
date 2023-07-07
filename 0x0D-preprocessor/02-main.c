#include <stdio.h>

/**
 * main - This program prints the name of the file where it was compiled from
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}

