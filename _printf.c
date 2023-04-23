#include "main.h"
#include <stdarg.h>

/**
 * _printf - output according to a the format specified
 * @format: A character string containing the format
 *
 * Return: The number of character printed
 */
int _printf(const char *format, ...)
{
	int char_printed = 0;
	char *s;
	int numb;
	va_list string_args;

	va_start(string_args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					_putchar(va_arg(string_args, int));
					char_printed++;
					break;
				}
				case 'd':
				case 'i':
				{
					numb = va_arg(string_args, int);
					char_printed += print_integer(numb);
				}
				case 's':
				{
					s = va_arg(string_args, char *);
					while (*s)
					{
						_putchar(*s);
						s++;
						char_printed++;
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					char_printed++;
					break;
				}
				default:
				{
					_putchar('%');
					_putchar(*format);
					char_printed += 2;
					break;
				}
			}
		}
		else
		{
			_putchar(*format);
			char_printed++;
		}
		format++;
	}
	va_end(string_args);

	return (char_printed);
}
