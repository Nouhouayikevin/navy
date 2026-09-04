/*
** EPITECH PROJECT, 2024
** the manipulations of the secret file
** File description:
** of navy
*/

#include "../include/my.h"

int verif_is_good_str(char *str)
{
    if (str[0] >= 'A' && str[0] <= 'H') {
        if (str[1] >= '1' && str[1] < '9')
            return 1;
        else
            return 0;
    } else
        return 0;
}

static int victory_cond(board_t *bd, int j)
{
    for (int i = 2; bd->board[j][i] != '\0'; i++) {
        if (bd->board[j][i] != '.' && bd->board[j][i] != ' ' &&
        bd->board[j][i] != 'o' && bd->board[j][i] != 'x')
            return 2;
    }
    return 1;
}

static void victory_cond2(board_t *bd, int j, int *k)
{
    for (int i = 2; bd->empty[j][i] != '\0'; i++)
        if (bd->empty[j][i] == 'x')
            *k = *k + 1;
}

int victory(board_t *bd, int enem_pid)
{
    int k = 0;

    for (int j = 2; bd->empty[j] != NULL; j++)
        victory_cond2(bd, j, &k);
    if (k == 14) {
        mini_printf("\nI won\n");
        return 0;
    }
    for (int j = 2; bd->board[j] != NULL; j++)
        if (victory_cond(bd, j) == 2)
            return 2;
    mini_printf("\nEnemy won\n");
    return 1;
}

char *read_attack(void)
{
    char *buf = NULL;
    size_t len;

    getline(&buf, &len, stdin);
    if (my_strlen(buf) != 3 || verif_is_good_str(buf) == 0 || *buf == '\0')
        return NULL;
    return buf;
}
