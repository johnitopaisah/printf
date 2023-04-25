#include "main.h"

/**
 * print_binary - print an unsiged integer in binary format
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_binary(unsigned int n)
{
	int i, count = 0;
	int bit;
	int leading_zero = 1;

	for (i = sizeof(n) * 8; i >= 0; i--)
	{
		bit = (n >> i) & 1;

		if (bit == 0 && leading_zero)
			continue;
		leading_zero = 0;
		count += _putchar(bit + '0');
	}

	return (count);
}
