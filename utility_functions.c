#include "main.h"

/**************************** is_digit Function ******************************/
/**
 * is_digit - Function that virifies if na char is a digit
 * @c: The character to evaluate
 *
 * Return: Return 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/********************** convert_size_number Function ***********************/
/**
 * convert_size_number - Function that casts a number to the specified size
 * @num: The number to be casted
 * @size: The number indicating the type to be casted
 *
 * Return: Return the casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/******************** conver_size_unsignd Function ***************************/
/**
 * convert_size_unsignd - Function that casts a number to the specified size
 * @num: The number to be casted
 * @size: The number indicating the type to be casted
 *
 * Return: Return the casted value of num
 */
long int convert_size_unsignd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/********************* is_printable Function ****************************/
/**
 * is_printable - Function that evaluates if a char is printable
 * @c: The character to be evaluated
 *
 * Return: Return 1 if is printabl, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/********************** append_hexa_code ******************************/
/**
 * append_hexa_code - Function that append ASCII in hexadecimal code to buffer
 * @buffer: The array of characters
 * @i: The index at which to start appending
 * @ascii_code: The ACCII CODE
 *
 * Return: Always return 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}
