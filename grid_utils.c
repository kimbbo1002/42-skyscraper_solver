#include "skyscraper.h"

int init_grid(t_grid *grid)
{
    grid->coltop = NULL;
    grid->colbottom = NULL;
    grid->rowleft = NULL;
    grid->rowright = NULL;

    grid->coltop = malloc(sizeof(int) * 4);
    if (!grid->coltop)
        return 0;
    grid->colbottom = malloc(sizeof(int) * 4);
    if (!grid->colbottom)
        return 0;
    grid->rowleft = malloc(sizeof(int) * 4);
    if (!grid->rowleft)
        return 0;
    grid->rowright = malloc(sizeof(int) * 4);
    if (!grid->rowright)
        return 0;
    return 1;
}

void clean_grid(t_grid *grid)
{
    if (grid->coltop)
        free(grid->coltop);
    if (grid->colbottom)
        free(grid->colbottom);
    if (grid->rowleft)
        free(grid->rowleft);
    if (grid->rowright)
        free(grid->rowright);
}

void print_grid(t_grid *grid)
{
    int i;

    i = 0;
    printf("  | ");
    while (i < 4)
    {
        printf("%d", grid->coltop[i]);
        printf(" | ");
        i++;
    }
    printf("\n");
    i = 0;
    while (i < 4)
    {
        printf("%d |               | %d\n", grid->rowleft[i], grid->rowright[i]);
        i++;
    }
    i = 0;
    printf("  | ");
    while (i < 4)
    {
        printf("%d", grid->colbottom[i]);
        printf(" | ");
        i++;
    }
}
