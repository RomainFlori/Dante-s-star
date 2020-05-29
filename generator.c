
/*
** EPITECH PROJECT, 2020
** directory
** File description:
** generator
*/

#include <stddef.h>
#include <stdio.h>
#include "my.h"

char **mapy(int x, int y)
{
    char **maze = malloc(sizeof(char *) * y + 1);

    if (x == 0 || y == 0)
        return NULL;
    if ((maze = malloc(sizeof(char *) * (y + 1))) == NULL)
        return NULL;
    for (int i = 0; i != y; i++) {
        maze[i] = malloc(sizeof(char) * x + 1);
    }
    for (int i = 0; i != y; i++) {
        for (int remp = 0; remp != x; remp++) {
            maze[i][remp] = 'X';
        }
    }
    return maze;
}

void generatorfct(int x, int y)
{
    char **maze = mapy(x, y);
    int rand = randomint(1, y);
    if (y == 1) rand = 0;
    for (int i = 0; i < x; i++) {
        if (i % 2 == 0) {
            for (int i2 = 0; i2 != y; i2++)
                maze[i2][i] = '*';
        }
        else continue;
    }
    for (int i = 0; i < x-1; i++)
        maze[rand][i] = '*';
    if (maze[0][0] == 'X')
        maze[0][0] = '*';
    if (maze[y-1][x-1] == 'X')
        maze[y-1][x-1] = '*';
    printmap(maze, y);
}

char **remove_sx(char **maze, int x)
{
    int nb_dx = 0;
    int rand;
    int i2;
    for (int i = 0; maze[i];i++) {
        for (int i22 = 0; maze[i][i22]; i22++)
            if (maze[i][i22] == 'X') nb_dx++;
        i2 = randomint(0, x);
        rand = randomint(0, (x-1));
        for (; maze[i][i2] && i2 != rand; i2++) {
            if (((maze[i][i2] == 'X') && nb_dx != 0 && rand != 0))
                maze[i][i2] = '*';
        }
        nb_dx = 0;
    }
    return maze;
}

void generatorfct_imp(int x, int y)
{
    char **maze = mapy(x, y);
    int rand = randomint(1, y);
    if (y == 1) rand = 0;
    if (rand == 0 && y != 1) rand = 1;
    for (int i = 0; i != x; i++)
        maze[0][i] = '*';
    for (int i = 0; i < x; i++) {
        if (i % 2 == 0) {
            for (int i2 = 0; i2 != y; i2++)
                maze[i2][i] = '*';
        }
        else continue;
    }
    for (int i = 0; i < x-1; i++)
        maze[rand][i] = '*';
    if (maze[0][0] == 'X') maze[0][0] = '*';
    if (maze[y-1][x-1] == 'X') maze[y-1][x-1] = '*';
    maze = remove_sx(maze, x);
    printmap(maze, y);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac < 3 || ac > 4) return 84;
    char *av1 = av[1];
    char *av2 = av[2];
    if (check_av(av1, av2) == 84) return 84;
    int x = atoi(av1);
    int y = atoi(av2);
    if (x <= 0 || y <= 0) return 84;
    if (ac == 4 && (perfect(av) == 2))
        generatorfct(x, y);
    else if (ac == 3)
        generatorfct_imp(x, y);
    else
        return 84;
    return 0;
}
