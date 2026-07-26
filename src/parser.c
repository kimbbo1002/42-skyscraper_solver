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
                grid->col_top[val_idx] = num;
            else if (val_idx < 8)
                grid->col_bottom[val_idx - 4] = num;
            else if (val_idx < 12)
                grid->row_left[val_idx - 8] = num;
            else
                grid->row_right[val_idx - 12] = num;
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
        if (grid->col_top[i] <= 0 || grid->col_top[i] > 4)
            return 0;
        else if (grid->col_bottom[i] <= 0 || grid->col_bottom[i] > 4)
            return 0;
        else if (grid->row_left[i] <= 0 || grid->row_left[i] > 4)
            return 0;
        else if (grid->row_right[i] <= 0 || grid->row_right[i] > 4)
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

void print_grid(t_grid *grid)
{
    int i;

    i = 0;
    printf("  | ");
    while (i < 4)
    {
        printf("%d", grid->col_top[i]);
        printf(" | ");
        i++;
    }
    printf("\n");
    i = 0;
    while (i < 4)
    {
        printf("%d |               | %d\n", grid->row_left[i], grid->row_right[i]);
        i++;
    }
    i = 0;
    printf("  | ");
    while (i < 4)
    {
        printf("%d", grid->col_bottom[i]);
        printf(" | ");
        i++;
    }
}