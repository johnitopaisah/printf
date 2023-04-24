#include "main.h"
#include <stdarg.h>
#include <stddef.h>

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
				case 's':
					count += print_strings(va_arg(strings_args, char *));
					break;
				switchCases(format[i]):
					break;
				default:
				{
					_putchar('%');
					_putchar(format[i]);
					count += 2;
				}
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
