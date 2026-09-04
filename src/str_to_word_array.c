/*
** EPITECH PROJECT, 2024
** str_to_word_array.c
** File description:
** Ceci est pour mon str_to_word_array
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../include/my.h"
#include <sys/stat.h>
static int ligne(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0'){
        if (str[i] == '\n')
            j++;
        i++;
    }
    return j;
}

char **like_main(int ac, char **av)
{
    char **map = NULL;
    char *str = NULL;
    int i = 0;
    int j = 0;

    if (ac == 2){
        if (open(av[1], O_RDONLY) == -1)
            return NULL;
        return take_map(av, i, j, 1);
    }
    if (ac == 3){
        if (open(av[2], O_RDONLY) == -1)
            return NULL;
        return take_map(av, i, j, 2);
    }
    return NULL;
}

char **take_map(char **av, int line, int col, int indice)
{
    char **map = NULL;
    int fd = 0;
    char *buf = NULL;
    int nb = 0;

    buf = malloc(sizeof(char) * (19 * 12 + 1));
    fd = open(av[indice], O_RDONLY);
    nb = read(fd, buf, 19 * 12 + 1);
    buf[nb] = '\0';
    line = ligne(buf) * 4;
    col = column(buf);
    map = stock(map, line + 1, col, buf);
    close(fd);
    return map;
}

int column(char *str)
{
    int i = 0;
    int j = 0;
    int col = 0;

    while (str[i] != '\0'){
        while (str[i] != '\n' && str[i] != '\0'){
            i++;
            j++;
        }
        if (str[i] == '\0')
            break;
        i++;
        if (j > col)
            col = j;
        j = 0;
    }
    return col;
}

char **allocation(int ligne, int col, char *str)
{
    int i = 0;
    char **map;

    map = malloc(sizeof(char *) * (ligne + 2));
    while (i < ligne + 1){
        map[i] = malloc(sizeof(char) * (col));
        i++;
    }
    return map;
}

static comp_t compteur(comp_t c)
{
    c.j++;
    c.c++;
    return c;
}

char **stock(char **map, int ligne, int col, char *str)
{
    comp_t c = {0, 0, 0};

    map = allocation(ligne + 1, col + 1, str);
    while (c.i < ligne && str[c.c] != '\0'){
        c.j = 0;
        while (c.j < col && (str[c.c] != '\n' && str[c.c] != ':')){
            map[c.i][c.j] = str[c.c];
            c = compteur(c);
        }
        if (str[c.c] == '\0'){
            map[c.i][c.j] = '\0';
            c.i++;
            break;
        }
        map[c.i][c.j] = '\0';
        c.i++;
        c.c++;
    }
    map[c.i] = NULL;
    return map;
}
