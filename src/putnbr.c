/*
** EPITECH PROJECT, 2024
** rush2
** File description:
** putnbr
*/
#include <stdio.h>
#include "../include/my.h"
int putnbr(int nbr)
{
    int n = 0;

    if (nbr < 0) {
        my_putchar('-');
        putnbr(-nbr);
    } else if (nbr > 9) {
        putnbr(nbr / 10);
        putnbr(nbr % 10);
    } else {
        my_putchar(nbr + '0');
    }
    n = nbrlen(nbr);
    return n;
}
