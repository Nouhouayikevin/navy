/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** This is a file for string copy
*/
#include <stdio.h>
#include <unistd.h>

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
