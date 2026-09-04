/*
** EPITECH PROJECT, 2024
** display_map.c
** File description:
** Display my map
*/
#include "../include/my.h"

void display_board(char **board)
{
    int i = 0;
    int j = 0;

    while (board[i] != NULL){
        mini_printf("%s\n", board[i]);
        i++;
    }
}

void print_table(board_t *boards)
{
    mini_printf("my navy:\n");
    display_board(boards->board);
    my_putchar('\n');
    mini_printf("enemy navy:\n");
    display_board(boards->empty);
    my_putchar('\n');
}

int get_attack(char c)
{
    if (c == 'A')
        return '1';
    if (c == 'B')
        return '2';
    if (c == 'C')
        return '3';
    if (c == 'D')
        return '4';
    if (c == 'E')
        return '5';
    if (c == 'F')
        return '6';
    if (c == 'G')
        return '7';
    if (c == 'H')
        return '8';
}

int get_attack_reverse(char c)
{
    if (c == '1')
        return 'A';
    if (c == '2')
        return 'B';
    if (c == '3')
        return 'C';
    if (c == '4')
        return 'D';
    if (c == '5')
        return 'E';
    if (c == '6')
        return 'F';
    if (c == '7')
        return 'G';
    if (c == '8')
        return 'H';
}

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (nbrlen(nb) + 1));
    int i = nbrlen(nb);
    int nbr = nbrlen(nb);
    int ver = 0;

    do {
        i--;
        if (i < 0)
            break;
        str[i] = (nb % 10) + 48;
        if (nb < 10){
            ver++;
        }
        if (ver > 1)
            break;
        nb = nb / 10;
    } while (ver < 2);
    str[nbr] = '\0';
    return str;
}
