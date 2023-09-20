#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: A string containing the characters and specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = handle_print(format, args);
	va_end(args);

	return (printed_chars);
}

/**
 * handle_print - Handles the printing of characters and format specifiers
 * @format: A string containing the characters and specifiers
 * @args: A va_list containing the arguments
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int handle_print(const char *format, va_list args)
{
	int i = 0, printed_chars = 0;

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else
			{
				int flags = get_flags(format, &i);
				int width = get_width(format, &i, args);
				int precision = get_precision(format, &i, args);
				int size = get_size(format, &i);
				int spec_chars = handle_specifier(format[i], args, flags, width, precision, size);
				if (spec_chars == -1)
					return (-1);
				printed_chars += spec_chars;
			}
		}
		i++;
	}

	return (printed_chars);
}
