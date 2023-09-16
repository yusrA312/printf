#include "main.h"

/**
 * printf_char - prints a char.
 * @va: arguments.
 * Return: 1.
 */
int printf_char(va_list v)
{
	char j;

	j = va_arg(val, int);
	_putchar(j);

	return (0);
}
