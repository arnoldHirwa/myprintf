#include "main.h"

/**
 * get_width - Extracts and returns the width specifier from the format string.
 * @format: The format string.
 * @i: A pointer to the current position in the format string.
 * @args: The va_list containing the variadic arguments.
 *
 * Return: The extracted width specifier.
 */
int get_width(const char *format, int *i, va_list args)
{
	int width = 0;

	if (format[*i] == '*')
	{
		width = va_arg(args, int);
		(*i)++;
	}
	else
	{
		while (is_digit(format[*i]))
		{
			width = width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}

	return (width);
}
