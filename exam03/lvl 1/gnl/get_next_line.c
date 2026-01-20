#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int next_line(char *str, int index)
{
    if (!str[index])
    {
        // printf("EOF\n");
        return (0);
    }
    while (str[index] && str[index] != '\n')
        index++;
    if (str[index])
        index++;
    return (index);
}


char *get_line(char *str, int *index)
{
    if (next_line(str, *index) == 0)
        return (NULL);
    char *ret = malloc(next_line(str, *index) + 1);
    if (!ret)
        return (NULL);
    int i = 0;
    // printf("index vaut : %d \n", *index);
    while (str[(*index)] && str[(*index)] != '\n')
    {
        // printf("test\n");
        ret[i] = str[(*index)];
        (*index)++;
        i++;
    }
    if (str[(*index)] == '\n')
    {
        ret[i] = str[(*index)];
        i++;
        (*index)++;
    }
    ret[i] = 0;
    return(ret);
}

char *get_next_line(int fd)
{
    static char str[999999];
    static int index;
    int x = 1;
    int i = 0;
    char *ret = NULL;
    // printf("index = %d\n", index);
    while (x > 0)
    {
        x = read(fd, &str[i], BUFFER_SIZE);
        i += x;
    }
    // printf("%s\n", str);
    ret = get_line((char *)str, &index);

    return(ret);
}

// int main()
// {
//     int fd;
//     char *str;

//     // int  i = 0;

//     fd = open("test.txt", O_RDONLY);

//     str = get_next_line(fd);
//     // printf("%s", str);
//     while (str != NULL)
//     {
//         printf("%s", str);
//         free(str);
//         str = get_next_line(fd);
//     }
// }