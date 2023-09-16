#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>



/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} codex;

int _putchar(char c);
int _printf(const char *format, ...);
int (*find_function(const char *format))(va_list);
int printf_per(void);
int printf_char(va_list v);
int printf_string(va_list v);
int printf_int(va_list args);

#endif
