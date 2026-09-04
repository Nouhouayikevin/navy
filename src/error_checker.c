/*
** EPITECH PROJECT, 2024
** navy
** File description:
** error_checker.c
*/

#include "../include/my.h"

int map_num(char **map)
{
    int i = 0;

    if (map_checker(map) == 84)
        return 84;
    for (i = 0; map[i] != NULL; i++){
        ;
    }
    return i;
}

int map_checker(char **map)
{
    int i = 0;

    if (map == NULL)
        return 84;
    while (map[i] != NULL){
        if (my_strlen(map[i]) > 1 && (map[i][1] > '8' || map[i][1] < '1'))
            return 84;
        i++;
    }
    return 12;
}

int deep_checker(char **map)
{
    if (map == NULL || map[0] == NULL || str_to_int(map[0]) != 2
    || str_to_int(map[3]) != 3 || str_to_int(map[6]) != 4
    || my_strlen(map[9]) == 0 || str_to_int(map[9]) != 5)
        return 84;
    return 0;
}

board_t *resulter(int state, char *str, board_t *board)
{
    int b = get_position(str[0]);

    if (state == 1)
        board->empty[str_to_int((char *)str + 1) + 1][b] = 'o';
    if (state == 2)
        board->empty[str_to_int((char *)str + 1) + 1][b] = 'x';
    return board;
}
