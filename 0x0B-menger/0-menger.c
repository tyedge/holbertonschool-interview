#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"


/**
 * menger - this function draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 */

void menger(int level)
{
	int i, j, k;

	if (level < 0)
		return;

	for (i = 0; i < pow(3, level); i++)
	{
		for (j = 0; j < pow(3, level); j++)
		{
			for (k =  pow(3, level) / 3; k; k /= 3)
			{
				if ((i % 3 == 1) && (j % 3 == 1))
				  break;
				if ((i % (k * 3)) / k == 1 && (
					    j % (k * 3)) / k == 1)
					break;
		        }
			if (!k)
			{
				printf("#");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}
