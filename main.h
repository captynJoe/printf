#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int _putchar(char character);
int print_char(va_list args, int printed);
int print_string(va_list args, int printed);
int print_integer(va_list args, int printed);
int selector(const char *format, va_list args, int printed);
int print_binary(unsigned int num, int printed);
int _printf(const char *format, ...);
int _x(unsigned int num, int printed, int uppercase);
int print_octal(unsigned int num, int printed);
int print_unsigned(unsigned int num, int printed);
int print_reverse(va_list args, int printed);
int print_pointer(va_list args, int printed);
int print_37(void);
int print_dec(va_list args);

#endif
