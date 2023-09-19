#include "main.h"



void print_buffer(char buf[], int *ind);



/**
* _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)

{

	int i, printed = 0, ch = 0;

	int flags, width, precision, size, ind = 0;

	va_list list;

	char buf[BUFF_SIZE];



	if (format == NULL)

		return (-1);



	va_start(list, format);



	for (i = 0; format && format[i] != '\0'; i++)

	{

		if (format[i] != '%')

		{

			buf[ind++] = format[i];

			if (ind == BUFF_SIZE)

				print_buffer(buf, &ind);

			/* write(1, &format[i], 1);*/

			ch++;

		}

		else

		{

			print_buffer(buf, &ind);

			flags = get_flags(format, &i);

			width = get_width(format, &i, list);

			precision = get_precision(format, &i, list);

			size = get_size(format, &i);

			++i;

			printed = handle_print(format, &i, list, buff,

					flags, width, precision, size);

			if (printed == -1)

				return (-1);

			ch += printed;

		}

	}



	print_buffer(buf, &ind);



	va_end(list);



	return (ch);

}



/**
* print_buffer - Prints the contents of the buffer if it exist
 * @ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buf[], int *ind)
{

	if (*ind > 0)

		write(1, &buf[0], *ind);



	*ind = 0;

}
