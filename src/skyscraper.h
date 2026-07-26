#ifndef SKYSCRAPER_H
#define SKYSCRAPER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_perm
{
    int value[4];
    int left;
    int right;
}   t_perm;

typedef struct s_grid
{
    int col_top[4];
    int col_bottom[4];
    int row_left[4];
    int row_right[4];
    t_perm perms[24];
}   t_grid;

typedef struct s_row
{
    int possible[24];
    int count;
}   t_row;

typedef struct s_board
{
    int rows[4];
}   t_board;

//parser.c
int check_args(int argc, char **argv, t_grid *grid);
void print_grid(t_grid *grid);

#endif