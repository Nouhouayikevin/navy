/*
** EPITECH PROJECT, 2024
** gestion of the connection
** File description:
** in navy battle ship
*/
#include "../include/my.h"
#include <signal.h>
static connect_value_t game_tick;


void signal_5(void)
{
    game_tick.state = 0;
    game_tick.attack1 = 0;
    game_tick.attack2 = 0;
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
    pause();
}

board_t *print_result(board_t *board, int ac, char **av)
{
    char *s = int_to_str(game_tick.attack1);
    int b = str_to_int((char *)s + 1);
    int a = 0;
    result_t c;

    s[0] = get_attack_reverse(s[0]);
    a = get_position(s[0]);
    c = (result_t) {board, 0, a, b};
    if (my_strcmp(result(board, b + 1, a), "hit") == 0 && ac == 2){
        kill(game_tick.enemy_pid, SIGUSR1);
        mini_printf("\nresult: %s:%s\n\n", s, result(board, b + 1, a));
        board->board[b + 1][a] = 'x';
    } else if (my_strcmp(result(board, b + 1, a), "missed") == 0 && ac == 2){
        kill(game_tick.enemy_pid, SIGUSR2);
        mini_printf("\nresult: %s:%s\n\n", s, result(board, b + 1, a));
        board->board[b + 1][a] = 'o';
    }
    board = cut_print_result(c, av, ac, s);
    return board;
}

static void connection_player2(int a, siginfo_t *signal, void *pas)
{
    if (a == SIGUSR2 && game_tick.connected == 0) {
        mini_printf("\nenemy connected\n");
        game_tick.connected = 1;
        game_tick.enemy_pid = signal->si_pid;
    }
    if (a == SIGUSR1 && game_tick.connected == 1) {
        game_tick.enemy_pid = signal->si_pid;
        kill(game_tick.enemy_pid, SIGUSR2);
    }
}

void attacking(char *str, int i, int ac, char **av)
{
    if (ac == 2){
        for (i = 0; i < str_to_int(str); i++){
            usleep(5000);
            kill(game_tick.enemy_pid, SIGUSR1);
        }
        for (i = str_to_int(str); i < 88; i++){
            usleep(5000);
            kill(game_tick.enemy_pid, SIGUSR2);
        }
    }
    if (ac == 3){
        for (i = 0; i < str_to_int(str); i++){
            usleep(5000);
            kill(str_to_int(av[1]), SIGUSR1);
        }
        for (i = str_to_int(str); i < 88; i++){
            usleep(5000);
            kill(str_to_int(av[1]), SIGUSR2);
        }
    }
}

static void receive(int a, siginfo_t *signal, void *pas)
{
    if (a == SIGUSR1)
        game_tick.attack1++;
    if (a == SIGUSR2)
        game_tick.attack2++;
}

static int connect_the_enemmy(int ac, char *str)
{
    if (ac == 3) {
        mini_printf("my_pid: %d\n", getpid());
        if (kill(str_to_int(str), SIGUSR2) == 0) {
            mini_printf("\nsuccessufully connected\n");
            game_tick.connected = 1;
            game_tick.enemy_connected = 1;
        } else
            return 84;
    }
}

void gaming(int a, siginfo_t *signal, void *pas)
{
    if (a == SIGUSR2){
        mini_printf("missed\n\n");
        game_tick.state = 1;
    }
    if (a == SIGUSR1){
        mini_printf("hit\n\n");
        game_tick.state = 2;
    }
}

static int player1(board_t *board, int ac, char **av)
{
    int nb = 0;
    struct sigaction sig;
    char *str = NULL;

    sig.sa_flags = SA_SIGINFO;
    while (1) {
        print_table(board);
        nb = victory(board, str_to_int(av[1]));
        if (nb == 1 || nb == 0)
            return nb;
        str = just_act(ac, av);
        acted(gaming);
        pause();
        board = resulter(game_tick.state, str, board);
        acted(nothing);
        mini_printf("waiting for enemy's attack...\n");
        acted(receive);
        board = player1_part1(ac, av, board);
    }
}

static int player2(board_t *board, int ac, char **av)
{
    int nb = 0;
    struct sigaction sig;
    char *str = NULL;

    sig.sa_flags = SA_SIGINFO;
    while (1) {
        print_table(board);
        nb = victory(board, str_to_int(av[1]));
        if (nb == 1 || nb == 0)
            return nb;
        acted(receive);
        mini_printf("waiting for enemy's attack...\n");
        summon_pause();
        acted(gaming);
        board = print_result(board, ac, av);
        str = just_act(ac, av);
        pause();
        board = pause_and_nothing(board, str, game_tick.state);
    }
}

int connection(int ac, char **av, board_t *board)
{
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = &connection_player2;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    if (ac == 2) {
        mini_printf("my_pid: %d\n\nwaiting for enemy...\n", getpid());
        pause();
    }
    if (connect_the_enemmy(ac, av[1]) == 84)
        return 84;
    if (ac == 2)
        return player1(board, ac, av);
    if (ac == 3)
        return player2(board, ac, av);
    return 0;
}
