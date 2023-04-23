#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - write c to the stdout
 * @c: character to be printed
 *
 * Return: return 1 on success.
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}


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
	int c;
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
					c = va_arg(string_args, int);
					_putchar(c);
					char_printed++;
					break;
				}
				case 's':
				{
					s = va_arg(string_args, char *);
					if (s == NULL)
					{
						s = "(nil)";
					}
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
