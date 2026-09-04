/*
** EPITECH PROJECT, 2024
** form_str_int.c
** File description:
** This is a file
*/
#include <unistd.h>
#include <stdio.h>
#include "../include/my.h"
int cut_str(int i, int n, char *str)
{
    while (i + 1 < my_strlen(str) && str[0] == '-'){
        if (i == 0)
            n = str[i + 1] - 48;
        else
            n = (n * 10) + (str[i + 1] - 48);
        i++;
    }
    while (i < my_strlen(str) && str[0] != '-'){
        if (i == 0)
            n = str[i] - 48;
        else
            n = (n * 10) + (str[i] - 48);
        i++;
    }
    return n;
}

int str_to_int(char *str)
{
    int n = 1;
    int i = 0;

    n = cut_str(i, n, str);
    if (str[0] != '-')
        return n;
    else
        return (n * -1);
}
