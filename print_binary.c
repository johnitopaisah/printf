#include "main.h"

/**
 * print_binary - print an unsiged integer in binary format
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_binary(unsigned int n)
{
	int count = 0;

	if (n > 1)
		count += print_binary(n / 2);
	count += _putchar((n % 2) + '0');

	return (count);
}
