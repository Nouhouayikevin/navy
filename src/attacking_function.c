/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** attacking_function.c
*/
#include "../include/my.h"

void summon_pause(void)
{
    signal_5();
    signal_1();
    signal_2();
    signal_3();
    signal_4();
}

char *attack_fct(int ac, char **av)
{
    char *str = read_attack();
    int i = 0;
    int j = 0;

    while (str == NULL) {
        mini_printf("\e[0m");
        mini_printf("\nwrong position\n\nattack: ");
        mini_printf("\e[3m");
        str = read_attack();
    }
    str[0] = get_attack(str[0]);
    str[2] = '\0';
    attacking(str, i, ac, av);
    return str;
}

board_t *player1_part1(int ac, char **av, board_t *board)
{
    summon_pause();
    acted(nothing);
    board = print_result(board, ac, av);
    return board;
}

void acted(void (*fcnt)(int, siginfo_t *, void *))
{
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = fcnt;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
}

board_t *cut_print_result(result_t c, char **av, int ac, char *str)
{
    int a = c.a;
    int b = c.b;
    board_t *bo = c.board;

    if (my_strcmp(result(c.board, b + 1, a), "hit") == 0 && ac == 3) {
        kill(str_to_int(av[1]), SIGUSR1);
        mini_printf("\nresult: %s:%s\n\n", str, result(bo, b + 1, a));
        c.board->board[b + 1][a] = 'x';
    } else if (my_strcmp(result(bo, b + 1, a), "missed") == 0 && ac == 3) {
        kill(str_to_int(av[1]), SIGUSR2);
        mini_printf("\nresult: %s:%s\n\n", str, result(bo, b + 1, a));
        c.board->board[b + 1][a] = 'o';
    }
    return c.board;
}
