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
    char tmp;
    char swap;
    int i = 0;
    int j;
    int index_swap = 0;;

    while(str[i])            //bcade = abede
    {
        j = i + 1;
        tmp = str[i];
        index_swap = i;
        while(str[j])
        {
            if (str[j] < tmp)
            {
                tmp = str[j];
                index_swap = j;
            }
            j++;
        }
        str[index_swap] = str[i];
        str[i] = tmp;
        i ++;
        //printf("swap n°%d, chaine = %s\n", i, str);
    }
}

int is_safe(char *str, int j, char *av, int i)
{
    while (j >= 0)
    {
        if (str[j] == av[i])
            return 0;
        j--;
    }
    return 1;
}

void solve(int av_len, char *av, char *str, int j)
{
    if (j == av_len)
    {
        //print
        printf("%s\n", str);
        return;
    }
    int i = 0;
    
    while (av[i])
    {
        if(is_safe(str, j, av, i) == 1)
        {
            str[j] = av[i];
            solve(av_len, av, str, j + 1);
            i++;
        }
        else 
            i++;
    }
    return;
}

int main(int ac , char **av)
{
    sort(av[1]);
    //printf("%s\n", av[1]);
    char *str = malloc(ft_strlen(av[1]) + 1);
    str[ft_strlen(av[1])] = 0;
    solve(ft_strlen(av[1]), av[1], str, 0);

}