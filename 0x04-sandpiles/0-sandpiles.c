#include "sandpiles.h"

/**
* print_grid - Prints a grid.
*
* @grid: Grid to be printed.
* Return: Nothing.
*/
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * check_grid_stable - checks if sandpile is stable
 * @grid1: initial sandpile
 * Return: 1 if grid1 stable, else 0.
 */
int check_grid_stable(int grid1[3][3])
{
	int i, j, stable;

	stable = 1;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				stable = 0;
				break;
			}
		}
		if (stable == 0)
		break;
	}
	return (stable);
}

/**
 * copy_grid1_to_grid2 - makes a copy of grid1
 * @grid1: initial sandpile
 * @grid2: sandpile to sum
 * Return: Nothing.
 */
void copy_grid1_to_grid2(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
		}
	}
}

/**
 * toppling_round - topple round sandpiles if unestable
 * @grid1: initial sandpile
 * @grid2: sandpile to sum
 * Return: Nothing.
 */
void toppling_round(int grid1[3][3], int grid2[3][3])
{
	int i, j, cols = 3, rows = 3;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] > 3)
			{
				if (i > 0)
					grid1[i - 1][j] += 1;
				if (j < (cols - 1))
					grid1[i][j + 1] += 1;
				if (i < (rows - 1))
					grid1[i + 1][j] += 1;
				if (j > 0)
					grid1[i][j - 1] += 1;
				grid1[i][j] -= 4;
			}
		}
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: initial sandpile
 * @grid2: sandpile to sum
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, stable;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (1)
	{
		stable = check_grid_stable(grid1);
		if (stable)
			break;
		printf("=\n");
		print_grid(grid1);
		copy_grid1_to_grid2(grid1, grid2);
		toppling_round(grid1, grid2);
	}
}
