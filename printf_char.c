#include "main.h"

/**
 * printf_char - prints a char.
 * @va: arguments.
 * Return: 1.
 */
int printf_char(va_list v)
{
	char j;

	va_start(v, format);

	j = va_arg(v, int);
	va_end(v);

	_putchar(j);

	return (1);
}
