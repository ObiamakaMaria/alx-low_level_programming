#include <stdio.h>
#include "main.h"

/**
 * main -  This function prints the name of the program
 * @argc:  This represents the number of arguments
 * @argv:  This represents the  array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}

