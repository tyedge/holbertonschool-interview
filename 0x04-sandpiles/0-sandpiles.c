#include "sandpiles.h"


/**
 * print_grid - prints 3x3 grid
 * @grid1: grid to be printed
 * Return: void
 */
static void print_grid(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}


/**
 * stable_chk - checks the stability of grid
 * @grid1: grid to be checked
 * Return: 1 if stable, 0 otherwise
 */
int stable_chk(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (0);
		}
	}
	return (1);
}


/**
 * toppler - topples grid
 * @grid1: grid to be toppled
 * @grid2: value grid
 * Return: void
 */
void toppler(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (j - 1 > -1)
					grid1[i][j - 1] += 1;
				if (j + 1 < 3)
					grid1[i][j + 1] += 1;
				if (i - 1 > -1)
					grid1[i - 1][j] += 1;
				if (i + 1 < 3)
					grid1[i + 1][j] += 1;
			}
		}
	}
}


/**
 * grid_sum - finds the sum of two grids
 * @grid1: grid to add
 * @grid2: grid to add
 * Return: void
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] +=  grid2[i][j];
		}
	}
}


/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: grid to add
 * @grid2: grid to add
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_sum(grid1, grid2);

	while (!stable_chk(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		toppler(grid1, grid2);
		stable_chk(grid1);
	}
}
