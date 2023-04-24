#include "main.h"
#include <stddef.h>


/**
 * print_strings - function that prints a string wint %s conversion specifier
 * @str: The pointer to the string to be printed
 *
 * Return: The total number of character printed
 */
int print_string(char *str)
{
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
