#include "main.h"

/**
 * print_binary - Function that handle the binary specifier
 * @num: The integer to be printed
 *
 * Return: The number of characters printed
 */
int print_binary(unsigned int num)
{
	int i = 0;
	int count = 0;
	int binary_digits[32];

	if (num == 0) /* if the number is zero, just print 0 */
	{
		_putchar('0');
		count++;
	}
	else
	{
		/* Converting the number to its binary */
		while (num > 0)
		{
			binary_digits[i] = num %= 2; /*storing the remainder in the binary_digit */
			num /= 2; /* The will update the number by dividing by 2 */
			i++;
		}

		/* Now print the digits in reverse order */
		while (i > 0)
		{
			_putchar(binary_digits[--i] + '0');
			count++;
		}
	}
	return (count);
}
