#include "main.h"

/**
 * switchCases - Function that checks for all the cases
 * @s: parameter
 *
 * Return: nothing.
 */
void switchCases(char s)
{
	int count = 0;

	if (s == 'c')
	{
		case 'c':
		{
			_putchar(s);
			count++;
		}
	}
	else if (s == 'd' || 'i')
	{
		case 'd':
		{
			count += print_integer(s);
		}
		case 'i':
		{
			count += print_strings(s);
		}
	}
	else
	{
		case '%':
		{
			_putchar('%');
			count++;
		}
	}
}
