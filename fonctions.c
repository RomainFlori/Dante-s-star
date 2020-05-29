/*
** EPITECH PROJECT, 2020
** directory
** File description:
** fonctions
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int randomint(int min, int max)
{
    int nb = 0;
    return (nb = rand() % ((max - min + 1)));
}

void printmap(char **map, int y)
{
    for (int i = 0; i != y; i++) {
        my_putstr(map[i]);
        if (i != y-1) my_putchar('\n');
    }
}
