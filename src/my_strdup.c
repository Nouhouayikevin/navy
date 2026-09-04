/*
** EPITECH PROJECT, 2024
** Day08
** File description:
** This is a file
*/
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

char *just_act(int ac, char **av)
{
    char *str = NULL;

    mini_printf("attack: ");
    mini_printf("\e[3m");
    str = str_for_attack(ac, av);
    mini_printf("\e[0m");
    mini_printf("\nresult: %s:", str);
    return str;
}

char *str_for_attack(int ac, char **av)
{
    char *str = NULL;

    str = attack_fct(ac, av);
    str[0] = get_attack_reverse(str[0]);
    return str;
}

void nothing(int a, siginfo_t *signal, void *pas)
{
    ;
}

char *my_strdup(char const *src)
{
    char *message;
    int i = 0;

    message = malloc(sizeof(char) * my_strlen(src));
    while (src[i] != '\0'){
        message[i] = src[i];
        i++;
    }
    message[i] = '\0';
    return message;
}
