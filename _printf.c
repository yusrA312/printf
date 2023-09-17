#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * find_function - function that finds formats for _printf
 * calls the corresponding function.
 * @format: format (char, string, int, decimal)
 * Return: NULL or function associated ;
 */
int (*find_function(const char *format))(va_list)
{
	unsigned int x = 0;
	codex find_codex[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_per},
		{"d", print_dec},
		{"i", print_int}
	};

	while (find_codex[x].sc)
	{
		if (find_codex[x].sc[0] == (*format))
			return (find_codex[x].f);
		x++;
	}
	return (NULL);
}
/**
 * _printf - function that produces output according to a format.
 * @format: format (char, string, int, decimal)
 * Return: size the output text;
 */
int _printf(const char *format, ...)
{
	va_list p;
	int (*f)(va_list);
	unsigned int i = 0, cpr = 0;

	if (format == NULL)
		return (-1);
	va_start(p, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cpr++;
			i++;
		}
		if (format[i] == '\0')
			return (cpr);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			cpr += f(p);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cpr++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(p);
	return (cpr);
}
