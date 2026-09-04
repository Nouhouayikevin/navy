/*
** EPITECH PROJECT, 2024
** usage.c
** File description:
** This is my usage
*/
#include "../include/my.h"
void usage(void)
{
    mini_printf("USAGE");
    mini_printf("    ./my_navy [first_player_pid] navy_positions\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("    first_player_pid: only for the second player.");
    mini_printf("pid of the first player.\n");
    mini_printf("    navy_positions: file representing the ");
    mini_printf("positions of the ships.\n");
}
