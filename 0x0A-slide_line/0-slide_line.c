#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"


/**
 * slide_line - this function slides and merges an array of integers
 * @line: array of integers to be slid and merged
 * @size: size of the array
 * @direction: direction in which the array must be slid
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t target = 0, pos1 = 0, pos2 = 1;
	size_t i, j, temp;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	pos1 = (direction == SLIDE_RIGHT) ? size - 1 : pos1;
	pos2 = (direction == SLIDE_RIGHT) ? size - 2 : pos2;
	for (i = 0; i < size; i++)
	{
		temp = pos2;
		target = 0;
		for (j = i + 1; j < size; j++)
		{
			if (line[pos1] != 0 && line[pos2] == line[pos1])
			{
				line[pos1] = line[pos1] * 2;
				line[pos2] = 0;
				break; }
			if (line[pos1] == 0 && line[pos2] != 0)
			{
				line[pos1] = line[pos2];
				line[pos2] = 0;
				target = 1;
				pos2 = temp;
				i--;
				break; }
			if (line[pos2] != 0)
				break;
			direction == SLIDE_LEFT ? pos2++ : pos2--;
		}
		if (line[pos1] == 0)
			break;
		if (target == 0)
		{
			pos1 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos1;
			pos2 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos2;
			pos1 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos1;
			pos2 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos2; }
	}
	return (1);
}
