/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** This is for my main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/my.h"
void free_tab(char **t)
{
    int k = 0;

    for (k = 0; t[k] != NULL; k++) {
        free(t[k]);
    }
    free(t);
}

char **verify_map(char **map)
{
    for (int i = 0; map[i] != NULL; i = i + 3) {
        if (map[i + 1][0] != map[i + 2][0] &&
        map[i + 2][0] - map[i + 1][0] + 1 != str_to_int(map[i]))
            return NULL;
        if (map[i + 1][1] != map[i + 2][1] &&
        map[i + 2][1] - map[i + 1][1] + 1 != str_to_int(map[i]))
            return NULL;
        if (map[i + 1][0] != map[i + 2][0] && map[i + 1][1] != map[i + 2][1])
            return NULL;
        if (map[i + 1][0] == map[i + 2][0] && map[i + 1][1] == map[i + 2][1])
            return NULL;
    }
    return map;
}

board_t *create_board(char **map)
{
    board_t *board = malloc(sizeof(board_t));

    if (verify_map(map) == NULL) {
        free_tab(map);
        return NULL;
    }
    board->board = create(map, create_a_map());
    board->empty = create_a_map();
    free_tab(map);
    return board;
}

void free_game_boards(board_t *board)
{
    free_tab(board->empty);
    free_tab(board->board);
}

static int verifier(int ac, char **av, board_t *game_board, int *nb)
{
    if (game_board == NULL)
        return 84;
    if (game_board->board == NULL)
        return 84;
    *nb = connection(ac, av, game_board);
    if (*nb == 84)
        return (*nb);
}

int main(int ac, char **av)
{
    int nb = 0;
    board_t *game_board = malloc(sizeof(board_t));

    if (ac < 2)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage();
        return 0;
    }
    game_board->map = like_main(ac, av);
    nb = error_handler(game_board->map);
    if (nb == 84)
        return 84;
    game_board = create_board(game_board->map);
    if (verifier(ac, av, game_board, &nb) == 84)
        return 84;
    free_game_boards(game_board);
    return nb;
}
