#include "main.h"
#include <stdarg.h>


/**
 * handle_format_specifier - Function that checks for all the cases
 * @args: The va_list containing the arguments
 * @format: The format specifier
 *
 * Return: The total number of character printed
 */
int handle_format_specifier(const char *format, va_list args)
{
	int count = 0;

	switch (*format)
	{
		case 'c':
		{
			_putchar(va_arg(args, int));
			break;
		}
		case 's':
		{
			count += (print_string(args));
			break;
		}
		case 'd':
		case 'i':
		{
			count += (print_integer(va_arg(args, int)));
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
			_putchar(*format);
			count += 2;
			break;
		}
	}
	return (count);
}
