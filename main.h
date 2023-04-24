#include <stdarg.h>

#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _strlen(char *str);
int print_integer(int num);
int _putchar(int c);
int print_string(va_list args);
int handle_format_specifier(const char *format, va_list args);

#endif /* MAIN_H */
