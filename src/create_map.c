/*
** EPITECH PROJECT, 2024
** create_map.c
** File description:
** This file is for create a map
*/
#include "../include/my.h"

char **the_other_lines(char **board)
{
    int k = 0;
    int i = 0;
    char j = '1';

    for (k = 0; k < 17; k++){
        if (k != 1)
            board[1][k] = '-';
        else
            board[1][k] = '+';
    }
    board[1][k] = '\0';
    i = 2;
    for (i = 2; i < 10; i++){
        board[i][0] = j;
        board[i][1] = '|';
        j++;
    }
    board[10] = NULL;
    return board;
}

char **the_points(char **board)
{
    int i = 2;
    int j = 2;

    while (i < 10){
        j = 2;
        while (j < 17){
            board[i][j] = '.';
            board[i][j + 1] = ' ';
            j += 2;
        }
        board[i][j - 1] = '\0';
        i++;
    }
    return board;
}

char **create_a_map(void)
{
    int c = 'A';
    int i = 2;
    int e = 0;
    char **board = malloc(sizeof(char *) * 13);

    for (e = 0; e < 11; e++)
        board[e] = malloc(sizeof(char) * 21);
    board[0][0] = ' ';
    board[0][1] = '|';
    for (c = 65; c < 73; c++){
        board[0][i] = c;
        i += 2;
        board[0][i - 1] = ' ';
    }
    board[0][i] = '\0';
    board = the_other_lines(board);
    board = the_points(board);
    return board;
}

int get_position(char c)
{
    if (c == 'A')
        return 2;
    if (c == 'B')
        return 4;
    if (c == 'C')
        return 6;
    if (c == 'D')
        return 8;
    if (c == 'E')
        return 10;
    if (c == 'F')
        return 12;
    if (c == 'G')
        return 14;
    if (c == 'H')
        return 16;
}

static char **cut_create(int i, char **map, char **board, char c)
{
    int k = map[i][1] - 47;
    int d = get_position(map[i][0]);

    if (map[i][1] == '\0' || map[i + 1] == NULL)
        return NULL;
    while (k <= map[i + 1][1] - 47){
        d = get_position(map[i][0]);
        while (d <= get_position(map[i + 1][0])){
            board[k][d] = c;
            d += 2;
        }
        k++;
    }
    return board;
}

char **create(char **map, char **board)
{
    int i = 0;
    int j = 0;
    int k = 2;
    char c = '1';
    int d = 2;

    while (map[i] != NULL){
        if (my_str_isnum(map[i]) == 1){
            c++;
            i++;
        } else {
            i++;
            continue;
        }
        board = cut_create(i, map, board, c);
        if (board == NULL)
            return NULL;
    }
    return board;
}
