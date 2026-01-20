#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    if (!str)
        return 0;

    int i = -1;
    while (str[++i])
        ;
    return i;
}

void    sort(char *str)
{
    int i = 0;
    char target;
    int index_to_swap;
    int j;
    while(str[i + 1])
    {
        j = i + 1;
        target = str[i];
        index_to_swap = i;
        while(str[j])
        {
            if (str[j] < target)
            {
                target = str[j];
                index_to_swap = j;
            }
            j++;
        }
        str[index_to_swap] = str[i];
        str[i] = target;
        i++;
    }
}

int     is_safe(char *tab, char c, int i)
{
    while(i > 0)
    {
        i--;
        if (tab[i] == c)
            return (1);
    }
    return (0);
}

void    solve(int av_len, char *tab, char *av, int i)
{
    int j = 0;
    // printf("%d\n", i);
    if (i == av_len)
    {
        printf("%s\n", tab);
        return;
    }
    while(av[j])
    {
        if(is_safe(tab, av[j], i) == 0)
        {
            tab[i] = av[j];
            solve(av_len, tab, av, i + 1);
        }
        j++;
    }
    return;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    char *tab = malloc(ft_strlen(av[1]) + 1);
    if (!tab)
        return 1;
    tab[ft_strlen(av[1])] = 0;
    sort(av[1]);
    // printf("sorted list : %s\n", av[1]);

    solve(ft_strlen(av[1]), tab, av[1], 0);
}