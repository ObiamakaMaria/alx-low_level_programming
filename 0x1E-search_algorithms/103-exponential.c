#include "search_algos.h"

/**
 * exponential_search - This function searches for a value in a sorted
 * array using Exponential search algorithm.
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: The value to search for
 * Return: The first index where the value is located, OR -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t low, high;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = bound < size ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	return (new_binary_search(array, low, high, value));
}

/**
 * new_binary_search - This function searches for a value in a sorted
 * array using Binary search algorithm.
 * @array: Pointer to the first element of the array to search in
 * @low: Starting index of the search range
 * @high: Ending index of the search range
 * @value: The value to search for
 * Return: The index where the value is located, OR -1 if not found
 */
int new_binary_search(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	while (low <= high)
	{
		print_array(array, low, high);

		mid = low + (high - low) / 2;

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return (-1);
}
/**
 * print_array - This function prints the elements of an array within
 * a given range
 * @array: Pointer to the first element of the array
 * @low: Starting index of the range
 * @high: Ending index of the range
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}
	printf("\n");
}
