#include "main.h"

/**
 * get_flags - Extracts and returns flags from the format string.
 * @format: The format string.
 * @i: A pointer to the current position in the format string.
 *
 * Return: The extracted flags as a bitmask.
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;

	while (1)
	{
		if (format[*i] == '-')
			flags |= F_MINUS;
		else if (format[*i] == '+')
			flags |= F_PLUS;
		else if (format[*i] == ' ')
			flags |= F_SPACE;
		else if (format[*i] == '0')
			flags |= F_ZERO;
		else if (format[*i] == '#')
			flags |= F_HASH;
		else
			break;
		(*i)++;
	}

	return (flags);
}
