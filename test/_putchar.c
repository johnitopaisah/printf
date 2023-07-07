#include "main.h"
#include <unistd.h>

/**
 * _putchar - write c to the stdout
 * @c: character to be printed
 *
 * Return: return 1 on success.
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
