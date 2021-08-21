#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

static void print_grid(int grid1[3][3]);
int stable_chk(int grid1[3][3]);
void toppler(int grid1[3][3], int grid2[3][3]);
void grid_sum(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
