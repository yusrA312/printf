#include "main.h"
/**
 * printf_string - print a string.
 * @va: argumen t.
 * Return: the length of the string.
 */

int printf_string(va_list va)
{
	char *s;
	int x, len;

	s = va_arg(va, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (x = 0; x < len; x++)
			_putchar(s[x]);
		return (len);
	}
	else
	{
		len = strlen(s);
		for (x = 0; x < len; x++)
			_putchar(s[x]);
		return (len);
	}
}
