#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using Jump Search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: The value to search for
 * Return: The first index where the value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step;
	size_t prev;

	if (array == NULL)
		return (-1);

	step = sqrt(size);
	prev = 0;

	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	while (array[min(step, size) - 1] < value)
	{
		prev = step;
		step += sqrt(size);
		if (prev >= size)
			return (-1);

		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, step);

	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	while (array[prev] < value)
	{
		prev++;

		if (prev == min(step, size))
			return (-1);

		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	}

	if (array[prev] == value)
		return ((int)prev);

	return (-1);
}

/**
 * min - Returns the minimum of two integers
 * @a: First integer
 * @b: Second integer
 * Return: The minimum of a and b
 */
size_t min(size_t a, size_t b)
{
	return ((b > a) ? a : b);
}
