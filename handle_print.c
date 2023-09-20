#include "main.h"

/**
 * handle_print - Handles the printing of formatted output.
 * @format: The format string.
 * @args: The va_list containing the variadic arguments.
 *
 * Return: The total number of characters printed.
 */
int handle_print(const char *format, va_list args)
{
	int i = 0;
	int printed_chars = 0;

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
			printed_chars++;
			i++;
		}
		else if (format[i + 1] != '\0')
		{
			i++;
			/* Call handle_specifier with appropriate arguments */
			printed_chars += handle_specifier(format[i], args, 0, 0, 0, 0);
		}
		else
			return (-1);

		i++;
	}

	return (printed_chars);
}
