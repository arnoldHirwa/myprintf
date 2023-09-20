#include "main.h"

/**
 * get_precision - Extracts and returns the precision specifier.
 * @format: The format string.
 * @i: A pointer to the current position in the format string.
 * @args: The list of arguments.
 *
 * Return: The precision value, or -1 if not found.
 */
int get_precision(const char *format, int *i, va_list args)
{
	int precision = -1;

	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
		{
			precision = va_arg(args, int);
			(*i)++;
		}
		else
		{
			precision = 0;
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				precision = precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
	}

	return (precision);
}
