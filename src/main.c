#include "skyscraper.h"

int main(int argc, char **argv)
{
    t_grid grid;

    if (!check_args(argc, argv, &grid))
        return 0;
    else
        print_grid(&grid);
}