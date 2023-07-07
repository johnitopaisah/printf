#include "main.h"

/************************* WRITE HANDLERS FUNCTIONS *************************/

/* This Handle Write Characters */
/**
 * handle_write_char - Function to prints a string
 * @c: character types
 * @buffer: The buffer array to handle print
 * @flags: To calcute the active flags
 * @width: The width specification
 * @precision: The precision specification
 * @size: The size specification
 *
 * Return: Return the number of characters printed
 */
int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size)
{
	/* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - print a string
 * @is_negative: Lists of argument
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get the width
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Return the number of characters printed
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags,
				width, precision, length, padd, extra_ch));
}

/************************ WRITE NUM *************************/
/**
 * write_num - Function that write number using buffer
 * @ind: The index at which the number starts on the buffer
 * @buffer: The buffer
 * @flags: To Caculate the active flags
 * @width: The width specifier
 * @prec: Precision specifier
 * @length: The number of length
 * @padd: Padding character
 * @extra_c: Extra character
 *
 * Return: The number of printed character
 */
int write_num(int ind, char buffer[],
		int flags, int width, int prec,
		int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0) no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is dosplayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		/*Assign extra character to left of buffer */
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* Extra char to left of buffer */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**************************** WRITE UNSIGND *****************************/
/**
 * write_unsignd - Function that writes an unsigned number
 * @is_negative: The number indicating if the num is negative
 * @ind: The index at which the number starts in the buffer
 * @buffer: The buffer of array of characters
 * @flags: To calculate the active flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: Return the number of characters written
 */
int write_unsignd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	/* The number of stored at the buffer's right and start at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0) no character is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Assign extra char to the left of buff*/
			return (write(1, &buffer[ind], length) +
					write(1, &buffer[0], i));
		else/* Asign extra char to left of padding [padd>buffer]*/
			return (write(1, &buffer[0], i) +
					write(1, &buffer[ind], length));
	}

	return (write(1, &buffer[ind], length));
}

/**************************** write pointer ******************************/
/**
 * write_pointer - Function that write a memory address
 * @buffer: Arrays of characters
 * @ind: Index at which the number starts in the buffer
 * @length: The length of number
 * @width: The width specifier
 * @flags: The flags specifier
 * @padd: The character representing the padding
 * @extra_c: The charactar representing the extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Return the number of characters written
 */
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) +
					write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) +
					write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
