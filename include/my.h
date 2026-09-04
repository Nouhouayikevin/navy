/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** Notre header
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <signal.h>
    #include <fcntl.h>
typedef struct compteur {
    int i;
    int j;
    int c;
}comp_t;
typedef struct connect_value {
    int enemy_pid;
    int enemy_connected;
    int connected;
    int attack1;
    int attack2;
    int state;
}connect_value_t;
typedef struct game_board {
    char **map;
    char **board;
    char **empty;
}board_t;
typedef struct result {
    board_t *board;
    char *str;
    int a;
    int b;
}result_t;
board_t *pause_and_nothing(board_t *board, char *str, int state);
char *just_act(int ac, char **av);
int victory(board_t *bd, int enem_pid);
board_t *resulter(int state, char *str, board_t *board);
board_t *print_result(board_t *board, int ac, char **av);
board_t *player1_part1(int ac, char **av, board_t *board);
int map_checker(char **map);
int deep_checker(char **map);
int map_num(char **map);
char *str_for_attack(int ac, char **av);
void attacking(char *str, int i, int ac, char **av);
void nothing(int a, siginfo_t *signal, void *pas);
board_t *cut_print_result(result_t c, char **av, int ac, char *str);
void gaming(int a, siginfo_t *signal, void *pas);
char *attack_fct(int ac, char **av);
char *result(board_t *bd, int a, int b);
void summon_pause(void);
void signal_1(void);
void signal_2(void);
void signal_3(void);
void attacking(char *str, int i, int ac, char **av);
void signal_4(void);
void signal_5(void);
char *attack_fct(int ac, char **av);
int get_attack(char c);
int get_attack_reverse(char c);
char *int_to_str(int nb);
void print_table(board_t *boards);
void acted(void (*fcnt)(int, siginfo_t *, void *));
char *read_attack(void);
char *read_from_file(void);
void write_in_file(char *str);
int connection(int ac, char **av, board_t *board);
void usage(void);
void display_board(char **board);
int get_position(char c);
char **create(char **map, char **board);
char **create_a_map(void);
int mini_printf(const char *format, ...);
char **like_main(int ac, char **av);
char **take_map(char **av, int line, int col, int indice_de_map);
int column(char *str);
char **allocation(int ligne, int col, char *str);
int my_str_isnum(char const *str);
int str_to_int(char *str);
int error_handler(char **map);
int nbrlen(int nb);
char **stock(char **map, int ligne, int col, char *str);
int cut_str(int i, int n, char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
int putnbr(int nbr);
int str_to_int(char *str);
#endif
