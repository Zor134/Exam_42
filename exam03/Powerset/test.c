#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    print_tab(int *tab, int tab_len)
{
    int i = 0;
    while (i < tab_len)
    {
        printf("[%d] ", tab[i]);
        i++;
    }
    printf("\n");
}


int *init_binary_tab(int ac, char **av)
{
    int *tab = malloc(sizeof(int) * (ac - 2));
    if (!tab)
        return (NULL);
    int i = -1;

    while (++i < ac - 2)
        tab[i] = 0;

    return (tab);
}

int *init_tab(int ac, char **av)
{
    int *tab = malloc(sizeof(int) * (ac - 2));
    if (!tab)
        return (NULL);
    int i = 0;
    while (i < ac - 2)
    {
        tab[i] = atoi(av[ac - (i + 1)]);
        i++;
    }
    // print_tab(tab, ac -2);
    return (tab);
}

int     increment_binary(int *binary_tab, int tab_len)
{
    int i = 0;
    while (1)
    {
        if (binary_tab[i] == 0)
            break;
        i++;
        if (i == tab_len)
            return 1;
    }

    if (binary_tab[tab_len] == 0)
        binary_tab[tab_len] = 1;
    else
    {
        while (binary_tab[tab_len] == 1)
        {
            binary_tab[tab_len] = 0;
            tab_len--;
        }
        binary_tab[tab_len] = 0;
    }
    return 0;
}

// void    solve(int *binary_tab, int tab_len, int *tab, int n)
// {
//     while(increment_binary(binary_tab, tab_len))
//     {
//         if (is_solution_right(binary_tab, tab_len, tab, n))
//             print_solution(binary_tab, tab_len, tab, n);
//     }
//     return;
// }

int main(int ac , char** av)
{
    int n = atoi(av[1]);
    int *binary_tab = init_binary_tab(ac, av);
    int *tab = init_tab(ac, av);
    // print_tab(tab, ac - 2);
    // print_tab(binary_tab, ac - 2);
    // solve(binary_tab, ac - 2, tab, n);

    int i = 0;
    while (i < 32)
    {
        increment_binary(binary_tab, ac - 2);
        print_tab(binary_tab, ac - 2);
        i++;
    }
}