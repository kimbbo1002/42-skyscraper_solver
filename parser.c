#include "skyscraper.h"
static int split_arg(char *argv, t_grid *grid)
{
    int i;
    int val_idx;
    int num;

    i = 0;
    val_idx = 0;
    while (argv[i])
    {
        if (!(i % 2))
        {
            num = argv[i] - '0';
            if (val_idx < 4)
                grid->coltop[val_idx] = num;
            else if (val_idx < 8)
                grid->colbottom[val_idx - 4] = num;
            else if (val_idx < 12)
                grid->rowleft[val_idx - 8] = num;
            else
                grid->rowright[val_idx - 12] = num;
            val_idx++;
        }
        else
        {
            if (argv[i] != ' ')
                return 0;
        }
        i++;
    }
    return (val_idx == 16);
}

static int check_grid_values(t_grid *grid)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (grid->coltop[i] <= 0 || grid->coltop[i] > 4)
            return 0;
        else if (grid->colbottom[i] <= 0 || grid->colbottom[i] > 4)
            return 0;
        else if (grid->rowleft[i] <= 0 || grid->rowleft[i] > 4)
            return 0;
        else if (grid->rowright[i] <= 0 || grid->rowright[i] > 4)
            return 0;
        i++;
    }
    return 1;

}

int check_args(int argc, char **argv, t_grid *grid)
{
    if (argc != 2)
    {
        printf("ERROR: This program only takes one argument.");
        return 0;
    }
    if (!split_arg(argv[1], grid))
    {
        printf("ERROR: Argument is not correctly defined.");
        return 0;
    }
    if (!check_grid_values(grid))
    {
        printf("ERROR: Argument values are not correctly configured.");
        return 0;
    }
    return 1;
}
