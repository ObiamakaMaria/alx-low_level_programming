#!/usr/bin/python3
"""
5-island_perimeter
"""

def island_perimeter(grid):
    """
    This function calculates the perimeter of the island described in grid.

    Args:
        grid (List[List[int]]): A list of lists representing the island grid.

    Returns:
        int: Perimeter of the island.
    """
    perimeter = 0
    
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4  # Start with the maximum perimeter
                
                # Check adjacent cells and subtract 1 from perimeter for each adjacent land cell
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1
                if i < len(grid) - 1 and grid[i + 1][j] == 1:
                    perimeter -= 1
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                if j < len(grid[i]) - 1 and grid[i][j + 1] == 1:
                    perimeter -= 1
    
    return perimeter

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))
