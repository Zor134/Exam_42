#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int **init_tab(int n)
{
    int **tab = malloc(sizeof(int*) * n);
    int i = 0;
    if (!tab)
        return NULL;
    while(i < n)
    {
        tab[i] = malloc(sizeof(int) * n);
        i++;
    }
    return (tab);
}

void    print_tab(int n, int **tab)
{
    //    printf("rentre dans print\n");
    int x = 0;
    int y = 0;

    while (x < n)
    {
        y = 0;
        while (y < n)
        {
            if (tab[y][x] == 1)
            {
                if (x != 0)
                    printf(" ");
                printf("%d", y);
            }
            y++;
        }
        x++;
    }
    printf("\n");
}

int     is_it_safe(int n , int**tab, int x, int y)
{
    int i = 0;
    while (i <= y)
    {
        // if (x - i >= 0 && tab[x-i][y] == 1)
        //     return(0);
        if (tab[x][y - i] == 1)
            return(0);
        if (x - i >= 0 && tab[x - i][y - i] == 1)
            return(0);
        if (x + i < n && tab[x + i][y - i] == 1)
            return(0);
        i++;
    }
    return (1); //is_safe
}

void    solve(int n, int **tab, int y)
{
    int x = 0;
    if (y == n)
    {
        print_tab(n, tab);
        return;
    }
    while(x < n)
    {
        if (is_it_safe(n, tab, x, y) == 1)
        {
            // printf("is safe\n");
            tab[x][y] = 1;
            solve(n, tab, y + 1);
            tab[x][y] = 0;
        }
        x++;
    }
    // printf("test\n");
    return;
}

int main(int ac , char **av)
{
    if (ac != 2)
        return(1);

    int n = atoi(av[1]);
    int **tab = init_tab(n);
    //    printf("test\n");
    solve(n, tab, 0);
    return 0;

}