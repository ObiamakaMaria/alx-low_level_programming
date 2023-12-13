#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array
 * using advanced binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: The value to search for
 * Return: The index where the first occurrence of value is
 *  located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (adv_binary_search(array, 0, size - 1, value));
}

/**
 * adv_binary_search - Recursive binary search function
 * @array: Pointer to the first element of the array to search in
 * @low: Starting index of the search range
 * @high: Ending index of the search range
 * @value: The value to search for
 * Return: The index where the first occurrence of value is
 * located, or -1 if not found
 */
int adv_binary_search(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	adv_print_array(array, low, high);

	mid = low + (high - low) / 2;

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		else
			return (adv_binary_search(array, low, mid, value));
	}
	else if (array[mid] < value)
		return (adv_binary_search(array, mid + 1, high, value));
	else
		return (adv_binary_search(array, low, mid - 1, value));
}

/**
 * adv_print_array - Prints the elements of an array within a given range
 * @array: Pointer to the first element of the array
 * @low: Starting index of the range
 * @high: Ending index of the range
 */
void adv_print_array(int *array, size_t low, size_t high)
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
