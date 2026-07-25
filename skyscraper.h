#ifndef SKYSCRAPER_H
#define SKYSCRAPER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_grid
{
    int *coltop;
    int *colbottom;
    int *rowleft;
    int *rowright;
}   t_grid;

// parser.c
int     check_args(int argc, char **argv, t_grid *grid);

//grid_utils.c
int     init_grid(t_grid *grid);
void    clean_grid(t_grid *grid);
void    print_grid(t_grid *grid);


#endif