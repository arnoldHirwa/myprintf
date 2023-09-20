#include "main.h"
#include "utils.c"

/**
 * print_unsigned - Print an unsigned integer
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: The number of characters printed
 */
int print_unsigned(va_list list, int flags, int width, int precision, int size)
{
    unsigned int u = get_unsigned_arg(list, size);
    char *str;
    int printed_chars = 0;

    str = _utoa(u, precision, 10);

    if (flags & F_MINUS)
        printed_chars += _printnstr(str, _strlen(str));

    while (printed_chars < (width - _strlen(str)))
    {
        _putchar(' ');
        printed_chars++;
    }

    if (!(flags & F_MINUS))
        printed_chars += _printnstr(str, _strlen(str));

    free(str);

    return (printed_chars);
}

/**
 * print_octal - Print an octal number
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: The number of characters printed
 */
int print_octal(va_list list, int flags, int width, int precision, int size)
{
    unsigned int u = get_unsigned_arg(list, size);
    char *str;
    int printed_chars = 0;

    str = _utoa(u, precision, 8);

    if (flags & F_HASH && str[0] != '0')
    {
        _putchar('0');
        printed_chars++;
    }

    if (flags & F_MINUS)
        printed_chars += _printnstr(str, _strlen(str));

    while (printed_chars < (width - _strlen(str)))
    {
        _putchar(' ');
        printed_chars++;
    }

    if (!(flags & F_MINUS))
        printed_chars += _printnstr(str, _strlen(str));

    free(str);

    return (printed_chars);
}

/**
 * print_hexadecimal - Print a hexadecimal number
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: The number of characters printed
 */
int print_hexadecimal(va_list list, int flags, int width, int precision, int size)
{
    unsigned int u = get_unsigned_arg(list, size);
    char *str;
    int printed_chars = 0;
    char prefix = '\0';

    str = _utoa(u, precision, 16);

    if (flags & F_HASH && u != 0)
    {
        prefix = (flags & F_UPPERCASE) ? 'X' : 'x';
        _putchar('0');
        printed_chars++;

        _putchar(prefix);
        printed_chars++;
    }

    if (flags & F_MINUS)
        printed_chars += _printnstr(str, _strlen(str));

    while (printed_chars < (width - _strlen(str)))
    {
        _putchar(' ');
        printed_chars++;
    }

    if (!(flags & F_MINUS))
        printed_chars += _printnstr(str, _strlen(str));

    free(str);

    return (printed_chars);
}
