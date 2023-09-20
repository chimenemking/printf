#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int put_car(char c);
int put_ss(char *c);
int print_char(va_list list);
int print_string(va_list list);
int print_percent(void);


int _printf(const char *format, ...);

#endif
