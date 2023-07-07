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
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

	while (mask > 0)
	{
		if (n & mask)
			count += _putchar('1');
		else
			count += _putchar('0');
		mask >>= 1;
	}
	return (count);
}
