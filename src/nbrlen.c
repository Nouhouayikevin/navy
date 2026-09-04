/*
** EPITECH PROJECT, 2024
** nbrlen.c
** File description:
** To count my number length
*/
#include <stdio.h>
#include "../include/my.h"
int nbrlenp(int nb, int nr)
{
    if ((nb >= 0) && (nb < 10)){
        nr++;
        return nr;
    }
    if (nb > 9){
        while (nb > 9){
            nb = nb / 10;
            nr++;
        }
        return (nr + 1);
    }
}

int nbrlenn(int nb, int nr)
{
    if ((nb <= 0) && (nb > -10)){
        nr++;
        return (nr + 1);
    }
    if (nb < -9){
        while (nb < -9){
            nb = nb / 10;
            nr++;
        }
        return (nr + 2);
    }
}

int nbrlen(int nb)
{
    int nr = 0;

    if (nb < 0){
        nr = nbrlenn(nb, nr);
    }
    if (nb > 0){
        nr = nbrlenp(nb, nr);
    }
    return nr;
}
