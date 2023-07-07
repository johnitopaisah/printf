#include "main.h"

/**************************** PRINT BINARY ******************************/
/**
 * print_binary - Function that prints an unsigned number
 * @types: The lists of arguments
 * @buffer: The buffer array to handle print
 * @flags: To calculate the active flags
 * @width: To get the width
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: Return the number of characters printed.
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/*********************** PRINT UNSIGNED NUMBER ******************************/
/**
 * print_unsigned - Function that prints an unsigned number
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: To calculate the active flags
 * @width: Th get the width
 * @precision: The precision specification
 * @size: The size specification
 *
 * Return: Return the number of characters printed
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/****************** PRINT UNSIGED NUMBER IN OCTAL ************************/
/**
 * print_octal - Function that prints an unsigned number in octal notation
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: To calculate the active flags
 * @width: To get the width
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: Return the number of characters printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/****************** PRINT UNSIGNED NUMBER IN HEXADECIMAL ********************/
/**
 * print_hexadecimal - Function that prints an unsigned number in hexadecimal
 * @types: The list of arguments
 * @buffer: The buffer of array to handle print
 * @flags: To calculate the active flags
 * @width: The width specification
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: Return the number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/******************* PRINT HEX NUMBER IN UPPER HEXADECIMAL ******************/
/**
 * print_hexa_upper - Function that prints an unsigned number in upper
 * hexadecimal notation
 * @types: The list of argument
 * @buffer: The buffer of array to handle print
 * @flags: To calculate the active flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: Return the number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
