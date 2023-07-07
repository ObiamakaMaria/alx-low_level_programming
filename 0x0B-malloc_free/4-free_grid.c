#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - This function frees a 2 dimensional array
 * @grid: This represents width of grid
 * @height: This represents height of grid
 * Return: This function returns free grid
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
