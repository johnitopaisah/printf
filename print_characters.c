#include "main.h"

/**
 * print_char - function that prints a single character
 * @c: charactr to be printed
 *
 * Return: the number of character printed
 */
int print_char(char c)
{
	int count = 0;

	if (c == '\0')
		return (0);
	_putchar(c);
	count++;
	return (count);
}
