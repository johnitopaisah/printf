#include "main.h"
#include <stddef.h>


/**
 * print_strings - function that prints a string wint %s conversion specifier
 * @args: The va_list strint to be printed
 *
 * Return: The total number of character printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
	{
		str = "(nil)";
	}
	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}
