#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of characters
 * @buff_ind: Index at which to add next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/******************** PRINT CHARACTERS ********************/
/**
 * print_char - Function that prints characters
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: To calculate the active flags
 * @width: The width specification
 * @precision: The precision specification
 * @size: The size specification
 *
 * Return: Return the number of chars printed
 */
int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/******************** PRINT A STRING ********************/
/**
 * print_string - Function that prints strings
 * @types: The list of arguments
 * @buffer: Buffer of array to be handle
 * @flags: To calculates the active flags
 * @width: The width specification
 * @precision: The precision specification
 * @size: The size specification
 *
 * Return: The number of characters printed
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}


/**************************** PRINT PERCENT SIGN *****************************/
/**
 * print_percent - prints a percent sign
 * @types: Lists of arguments
 * @buffer: The buffer of array to handle the print
 * @flags: To calculate the active flags
 * @width: get the width
 * @precision: The precision specification
 * @size: The size specifier.
 *
 * Return: Return the number of characters printed
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)

{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**************************** PRINT INT ******************************/
/**
 * print_int - Function that print integers
 * @types: The list of arguments
 * @buffer: The buffer of array to handle print
 * @flags: To calculate the active flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: Return the number of charactes printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	unsigned long int num;

	long int n = va_arg(types, long int);

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
