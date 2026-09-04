/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** my str is num
*/
#include <stdio.h>
#include "../include/my.h"
int my_str_isnum(char const *str)
{
    int i = 0;
    char c;

    while (str[i] != '\0'){
        c = str[i];
        if ((c < 48) || (c > 57)){
            return 0;
        }
        i++;
    }
    return 1;
}
