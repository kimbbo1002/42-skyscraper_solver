#include "skyscraper.h"

static void save_perm(t_grid *grid, int *current, int *index)
{
    int i;

    i = 0;
    while (i < 4)
    {
        grid->perms[*index].value[i] = current[i];
        i++;
    }

    (*index)++;
}

static void generate_perm(t_grid *grid, int *current,
                          int *used, int depth, int *index)
{
    int i;

    if (depth == 4)
    {
        save_perm(grid, current, index);
        return;
    }

    i = 1;
    while (i <= 4)
    {
        if (!used[i])
        {
            used[i] = 1;
            current[depth] = i;

            generate_perm(grid, current,
                          used, depth + 1, index);

            used[i] = 0;
        }
        i++;
    }
}

void init_perms(t_grid *grid)
{
    int current[4];
    int used[5];
    int index;
    int i;

    index = 0;

    i = 0;
    while (i < 5)
    {
        used[i] = 0;
        i++;
    }

    generate_perm(grid, current, used, 0, &index);
}

int main(void)
{
    t_grid grid;
    int i;

    init_perms(&grid);

    i = 0;
    while (i < 24)
    {
        printf("%d%d%d%d\n",
            grid.perms[i].value[0],
            grid.perms[i].value[1],
            grid.perms[i].value[2],
            grid.perms[i].value[3]);
        i++;
    }
}