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
	char *s;
	int numb;
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
				{
					numb = va_arg(string_args, int);
					count += print_integer(numb);
					break;
				}
				case 's':
				{
					s = va_arg(string_args, char *);
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						_putchar(*s);
						s++;
						count++;
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					count++;
					break;
				}
				default:
				{
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
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
