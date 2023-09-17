#include "main.h"

void print_buffer(char buffers[], int *buff);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, chars = 0;
	int flags, width, precision, size, buff = 0;
	va_list list;
	char buffers[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffers[buff++] = format[i];
			if (buff == BUFF_SIZE)
				print_buffer(buffers, &buff);
			/* write(1, &format[i], 1);*/
			chars++;
		}
		else
		{
			print_buffer(buffers, &buff);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars += printed;
		}
	}

	print_buffer(buffers, &buff);

	va_end(list);

	return (chars);
}

/**
 * print_buffer - Prints the contents of the buffers if it exist
 * @buffers: Array of chars
 * @buff: Index at which to add next char, represents the length.
 */
void print_buffer(char buffers[], int *buff)
{
	if (*buff > 0)
		write(1, &buffers[0], *buff);

	*buff = 0;
}
