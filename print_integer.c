#include "main.h"


/**
 * print_integer - prints an integer.
 * @num: the integer to be printed.
 *
 * Return: The number of character printed.
 */
int print_integer(int num)
{
	int count = 0; /* Number of characters printed */
	int num_digits = 0; /* Number of digits in the integer */
	int divisor = 1; /* For extracting each digit */
	int digit; /* For extracting the leftmost digit */
	int temp; /* For tempurally storage */

	if (num < 0)
	{
		_write('-'); /* Write a negative sign to the stdout */
		count++;
		num = -num; /* Convert the number to positive */
	}

	temp = num;
	while (temp > 0)
	{
		temp /= 10; /* count the number of digits */
		num_digits++;
	}

	while (--num_digits > 0)
	{
		divisor *= 10; /* To calculate the divisor based on the number of digits */
	}

	while (divisor > 0)
	{
		digit = num / divisor; /* This will extrat the leftmost digit */
		_write(digit + '0'); /* Write the digit as a character */
		count++;
		num %= divisor; /* To update the number by removing the leftmost digit */
		divisor /= 10; /* This will update the divisor for the next digit */
	}

	return (count);
}
