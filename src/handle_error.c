/*
** EPITECH PROJECT, 2024
** handle_error.c
** File description:
** This code is for error handling
*/
#include "../include/my.h"
static int cut_error_handler(char **map, int i, int k)
{
    if (str_to_int(map[i]) == 0){
        if ((map[i][0] < 65 || map[i][0] > 72) && my_strlen(map[i]) > 1)
            return 84;
        if ((map[i][1] < 49 || map[i][1] > 56) && my_strlen(map[i]) > 1)
            return 84;
    }
    if (str_to_int(map[i]) == 1 && map[i][0] != k)
        return 84;
    return 1;
}

int error_handler(char **map)
{
    int i = 0;
    int j = 0;
    int k = '2';

    if (map_num(map) != 12)
        return 84;
    if (deep_checker(map) == 84)
        return 84;
    while (map[i] != NULL){
        if (cut_error_handler(map, i, k) == 84)
            return 84;
        if (str_to_int(map[i]) == 1)
            k++;
        i++;
    }
    for (i = 0; map[i] != NULL; i++)
        if (my_str_isnum(map[i]) == 1 && map[i + 2] != NULL &&
        map[i + 1][0] != map[i + 2][0] && map[i + 1][1] != map[i + 2][1])
            return 84;
    return 0;
}
