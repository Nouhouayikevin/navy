/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** This is My mini print_f file.
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../include/my.h"
int handle_coding(const char *format, va_list args, int i, int count)
{
    char c;

    c = format[i + 1];
    if ((format[i] == 37) && (format[i + 1] == 99)){
        my_putchar(va_arg(args, int));
        count++;
    }
    if ((format[i] == 37) && (format[i + 1] == 's')){
        count = count + my_putstr(va_arg(args, char *));
    }
    if ((format[i] == 37) && (format[i + 1] == 37)){
        my_putchar('%');
        count++;
    }
    if ((format[i] == 37) && ((c == 'd') || (c == 'i'))){
            count = count + putnbr(va_arg(args, int));
            i++;
    }
    return count;
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;
    char c;

    va_start(args, format);
    while (i < my_strlen((char *)format)){
        c = format[i + 1];
        if (format[i] != '%' && ((format[i - 1] != 37) || (format[i] == 32))){
            my_putchar(format[i]);
            i++;
            count++;
        } else {
            count = handle_coding(format, args, i, count);
            i++;
            i++;
        }
    }
    va_end(args);
    return count;
}
