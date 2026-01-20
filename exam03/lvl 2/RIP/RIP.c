#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int    remove_calcul(char *str)
{
    // printf("str = %s\n", str);
    int o = 0;
    int c = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] == '(')
            o++;
        else if (str[i] == ')')
        {
            if(o > 0)
                o--;
            else
                c++;
        }
        i++;
    }
    // printf("return calcul = %d\n", o + c);
    return (o + c);
}

void    solve(char *str, int target, int i )
{

    if (target == 0)
    {
        // printf("target == 0\n");
        if (remove_calcul(str) == 0)
            puts(str);
        return;
    }
    char c;
    while(str[i])
    {
        c = str[i];
        str[i] = ' ';
        solve(str, target - 1, i + 1);
        str[i] = c;
        i++;
    }
    return;
}

int main(int ac, char ** av)
{
    if (ac != 2)
        return 1;
    solve(av[1], remove_calcul(av[1]),0);
}