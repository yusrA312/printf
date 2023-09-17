#include "main.h"

/**
 * get_width - Calculates the wid for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: wid.
 */
int get_width(const char *format, int *i, va_list list)
{
	int x;
	int wid = 0;

	for (x = *i + 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			wid *= 10;
			wid += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = x - 1;

	return (wid);
}
