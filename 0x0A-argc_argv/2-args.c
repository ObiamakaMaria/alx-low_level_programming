#include <stdio.h>
#include "main.h"

/**
 * main - This function prints all arguments it receives
 * @argc: This represents the number of arguments
 * @argv: This represents array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}

