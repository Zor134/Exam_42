#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void    print_tab_exam(int **tab, int n)
{
    int x = n - 1;
    int y = 0;
    int i = 0;

    while (y < n)
    {
        x = n - 1;
        i = 0;
        while(x >= 0)
        {
            if (tab[y])
            i++;
            x--;
        }
        y++;
    }
}
void    print_tab(int **tab, int n)
{
    int x = 0;
    int y = 0;

    while (x < n)
    {
        y = 0;
        while (y < n)
        {
            printf("[%d]", tab[x][y]);
            y++;
        }
        printf("\n");
        x++;
    }
    printf("\n");
}
// is is safe
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
void    solve(int n , int **tab, int y)
{
    int x = 0;

    if (y == n)
    {
        print_tab(tab, n);
        return;
    }
    while(x < n)
    {
        if (is_it_safe(n, tab, x, y) == 1)
        {
            tab[x][y] = 1;
            solve(n, tab, y + 1);
            tab[x][y] = 0;
        }
        x++;
    }
    return;
}

int main(int ac, char **argv)
{
    if (ac != 2)
        return 1;
    int n = atoi(argv[1]);


    int **tab = malloc(sizeof(int *)* n);
    int x = 0;
    int y = 0;

    while (x < n)
    {
        y = 0;
        tab[x] = malloc(sizeof(int) * n);
        while (y < n)
        {
            tab[x][y] = 0;
            y++;
        }
        x++;
    }
    print_tab(tab, n);
    solve(n , tab, 0);

}