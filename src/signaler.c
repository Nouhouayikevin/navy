/*
** EPITECH PROJECT, 2024
** signaler.c
** File description:
** This is for handle signal
*/
#include "../include/my.h"
void signal_1(void)
{
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
}

void signal_2(void)
{
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
}

void signal_3(void)
{
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
}

void signal_4(void)
{
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
}

char *result(board_t *bd, int a, int b)
{
    if (bd->board[a][b] != '.' &&
    bd->board[a][b] != 'x' &&
    bd->board[a][b] != 'o') {
        return "hit";
    } else {
        return "missed";
    }
}
