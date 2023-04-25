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
	int i = 0, count = 0;
	va_list string_args;

	va_start(string_args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				{
					_putchar(va_arg(string_args, int));
					count++;
					break;
				}
				case 'd':
				case 'i':
					count += print_integer(va_arg(string_args, int));
					break;
				case 's':
					count += print_string(va_arg(string_args, char *));
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(string_args);

	return (count);
}
