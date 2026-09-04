/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** my_putchar file
*/
#include <unistd.h>
#include "../include/my.h"
board_t *pause_and_nothing(board_t *board, char *str, int state)
{
    board = resulter(state, str, board);
    acted(nothing);
    return board;
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
