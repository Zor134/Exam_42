#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    print_tab(int *tab, int tab_len)
{
    int i = 0;
    while(i <= tab_len)
    {
        printf("[%d]", tab[i]);
        i++;
    }
    printf("\n");
}

int     how_many_ones(int *binary_tab, int tab_size)
{
    int i = 0;
    int count = 0;
    while (i <= tab_size)
    {
        if (binary_tab[i] == 1)
            count++;
        i++;
    }
    return (count);
}

void    print_solution(int *binary_tab, int *tab, int tab_size)
{
    int ones = how_many_ones(binary_tab, tab_size);
    while (tab_size >= 0)
    {
        if (binary_tab[tab_size] == 1)
        {
            printf("%d", tab[tab_size]);
            if(ones != 1)
            {
                ones--;
                printf(" ");
            }
        }
        tab_size--;
    }
    printf("\n");
}

int    increment_binary(int *binary_tab, int tab_size)
{
    int i = 0;

    while(i <= tab_size) // check si tableau est rempli de 1 si oui renvoie 0
    {
        if (binary_tab[i] == 1)
            i++;
        else 
            break;
        if (i == tab_size + 1)
            return (0);
    }
    while (tab_size > 0)
    {
        if (binary_tab[tab_size] == 0)
        {
            binary_tab[tab_size] = 1;
            break;
        }
        else
        {
            while(binary_tab[tab_size] == 1) // tant que ne tombe pas sur 0 remplace par 0
            {
                binary_tab[tab_size] = 0;
                tab_size--;
            }
            binary_tab[tab_size] = 1;   // remplace par 1 le premier zero apres 1
            break;                       
        }
        tab_size--;
    }
    return(1);
}

int     is_combination_right(int n, int *tab, int *binary_tab, int tab_len)
{
    int res = 0;
    int i = 0;
    while (i <= tab_len)
    {
        if (binary_tab[i] == 1)
            res += tab[i];
        i++;
    }
    if (res == n)
        return (0);
    else 
        return (1);
}

void    solve(int n, int *tab, int *binary_tab, int tab_size)
{
    while(increment_binary(binary_tab, tab_size) != 0)
    {
        if (is_combination_right(n, tab, binary_tab, tab_size) == 0)
            print_solution(binary_tab, tab, tab_size);
    }
}


int main(int ac, char **argv)
{
    int tab_size = ac - 2;
    int i = 2;
    int n = atoi(argv[1]);
    int *tab = malloc(sizeof(int) * tab_size);
    // printf("test\n");
    while (tab_size > 0)
    {
        tab[tab_size - 1] = atoi(argv[i]);
        i++;
        tab_size--;
    }
    tab_size = ac - 2;

    int *binary_tab = malloc(sizeof(int) * tab_size);
    while (tab_size > 0)
    {
        binary_tab[tab_size - 1] = 0;
        i++;
        tab_size--;
    }
    tab_size = ac - 2;
    print_tab(tab, tab_size - 1);
    // int y = 0;
    // while (y < 32)
    // {
    //     increment_binary(binary_tab, tab_size - 1);
    //     print_tab(binary_tab, tab_size - 1);
    //     y++;
    // }
    solve(n, tab, binary_tab, tab_size - 1);
    // printf("test\n");

}
