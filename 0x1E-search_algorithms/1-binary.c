#include <stdio.h>
#include "search_algos.h"

/**
 * binary_searchs function searches for a value in a 
 * sorted array using binary search algorithm.
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Returns the index where value is located, OR
 * -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left_half = 0, right_half = size - 1, mid;

	if (array == NULL)
		return (-1);

	while (left_half <= right_half)
	{
		print_array(array, left_half, right_half);

		mid = (left_half + right_half) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left_half = mid + 1;
		else
			right_half = mid - 1;
	}

	return (-1);
}

/**
 * print_array - Prints the elements of an array within a specified range
 * @array: Pointer to the first element of the array
 * @start: Starting index for printing
 * @end: Ending index for printing
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: %d", array[start]);
	for (i = start + 1; i <= end; i++)
	{
		printf(", %d", array[i]);
	}
	printf("\n");
}
