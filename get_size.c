#include "main.h"

/**
 * get_size - Extracts and returns the size specifier.
 * @format: The format string.
 * @i: A pointer to the current position in the format string.
 *
 * Return: The size specifier value, or SIZE_NONE if not found.
 */
int get_size(const char *format, int *i)
{
    int size = SIZE_NONE;

    if (format[*i] == 'h')
    {
        size = S_SHORT;
        (*i)++;
        if (format[*i] == 'h')
        {
            size = S_CHAR;
            (*i)++;
        }
    }
    else if (format[*i] == 'l')
    {
        size = S_LONG; 
        (*i)++;
        if (format[*i] == 'l')
        {
            size = S_LONG_LONG;
            (*i)++;
        }
    }
    else if (format[*i] == 'L')
    {
        size = S_LONG_DOUBLE;
        (*i)++;
    }

    return (size);
}
