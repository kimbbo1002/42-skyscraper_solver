#include "skyscraper.h"

int main(int argc, char **argv)
{
    t_grid grid;

    if (!init_grid(&grid) || !check_args(argc, argv, &grid))
    {
        clean_grid(&grid);
        return 0;
    }
    else
        print_grid(&grid);
}