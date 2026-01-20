#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1

void    replace_with_stars(char *str, int l, int len)
{
    while (len > 0)
    {
        str[l] = '*';
        len--;
        l--;
    }
    return;
}

int main(int count, char **arg)
{
    int i = 0;
    int j = 0;
    int l = 0;
    int ret = 1;
    char str[99999];

    if (count != 2 || !arg[1][0])
        return(1);
    // printf("apres return\n");
    while (ret > 0)
    {
        ret = read(0, &str[i], BUFFER_SIZE);
        if (ret < 0)
		{
			perror("Error: ");
			return (1);
		}
        i+=ret;
    }
    // printf("%lu %s\n", strlen(str), str);
    i = 0;
    while (str[i])
    {
        j = 0;
        if (arg[1][j] == str[i])
        {
            l = i;
            while (arg[1][j] == str[l])
            {
                l++;
                j++;
                if (!arg[1][j])
                    replace_with_stars(str, l - 1, strlen(arg[1]));
            }
        }
        i++;
    }
    printf("%s", str);
}