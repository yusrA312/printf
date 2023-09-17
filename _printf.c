"main.h"


int _printf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	int chars_printed = 0;

	while (*format) {
		if (*format != '%') {
			write(1, format, 1);
			chars_printed++;
		} else {
			format++; // Move past '%'
			int left_justified = 0;
			int zero_padding = 0;

			// Check for flags
			while (*format == '-' || *format == '0') {
				if (*format == '-') {
					left_justified = 1;
				} else if (*format == '0') {
					zero_padding = 1;
				}
				format++;
			}

			// Check for width
			int width = 0;
			while (*format >= '0' && *format <= '9') {
				width = width * 10 + (*format - '0');
				format++;
			}

			// Handle format specifiers
			if (*format == 'd') {
				int num = va_arg(args, int);
				if (left_justified) {
					// Print the number left-justified with zero-padding if specified
					int printed = 0;
					if (num < 0) {
						write(1, "-", 1);
						num = -num;
						printed++;
					}
					while (printed < width - count_digits(num)) {
						write(1, zero_padding ? "0" : " ", 1);
						printed++;
					}
					char num_char = num + '0';
					write(1, &num_char, 1);
				} else {
					// Print the number right-justified with zero-padding if specified
					int printed = 0;
					while (printed < width - count_digits(num)) {
						write(1, zero_padding ? "0" : " ", 1);
						printed++;
					}
					char num_char = num + '0';
					write(1, &num_char, 1);
				}
			} else if (*format == 's') {
				char *str = va_arg(args, char *);
				write(1, str, strlen(str));
			} else if (*format == 'c') {
				char c = va_arg(args, int); // Characters are promoted to int in va_arg
				write(1, &c, 1);
			} else {
				// Unsupported format specifier, just print it
				// write(1, "%", 1);
				write(1, format, 1);
				chars_printed += 2;
			}
		}
		format++;
	}

	va_end(args);
	return chars_printed;
}

int count_digits(int num) {
	int count = 0;
	while (num != 0) {
		num /= 10;
		count++;
	}
	return count;
}
