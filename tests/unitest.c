/*
** EPITECH PROJECT, 2024
** unit test
** File description:
** of radar
*/

#include "../include/my.h"
#include <criterion/criterion.h>
int my_strlen(const char *s);
char *my_strdup(char const *src);
int my_putstr(char const *s);

Test(nbrlen, azerty)
{
    int a = 0;
    a = my_strlen("PAPA");
    char *str = my_strdup("PAPA");
    cr_assert_eq(a, 4);
    cr_assert_neq(a, 0);
    cr_assert_str_eq("PAPA", str);
    cr_assert_str_neq("PAPA", "PAP");
    my_putstr("LE GRADE A");
    cr_assert_eq(my_putstr("LE GRADE A"), 0);
    cr_assert_neq(my_putstr("LE GRADE A"), 1);
    free(str);
}
