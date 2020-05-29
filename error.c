/*
** EPITECH PROJECT, 2020
** directory
** File description:
** error
*/

#include "my.h"

int perfect(char **av)
{
    char *b = av[3];
    int i = 0;
    if (b[0] == 'p' && b[1] == 'e' && b[2] == 'r' && b[3] == 'f')
        i++;
    if (b[4] == 'e' && b[5] == 'c' && b[6] == 't')
        i++;
    return i;
}

int check_av(char *av1, char *av2)
{
    int error = 0;
    int ret = 0;
    int par = 0;

    if (!(av1[par] >= '0' && av1[par] <= '9'))
        error++;
    if (!(av2[par] >= '0' && av2[par] <= '9'))
        error++;
    if (error != 0) ret = 84;
    return ret;
}