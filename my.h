/*
** EPITECH PROJECT, 2020
** directory
** File description:
** my
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#ifndef MY_H_
#define MY_H_
int main(int ac, char **av);
void fct(char const *str, int i, int y, int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int check_av(char *av1, char *av2);
int perfect(char **av);
int randomint(int min, int max);
void printmap(char **map, int y);

typedef struct maze_s
{
    int nord;
    int sud;
    int hauteur;
    int largeur;
}maze_s_t;

#endif /* !MY_H_ */
