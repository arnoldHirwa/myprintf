#include "main.h"
#include "utils.c"

/**
 * print_char - Print a character
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier (not used)
 *
 * Return: The number of characters printed
 */
int print_char(va_list list, int flags, int width, int precision, int size)
{
    char c = va_arg(list, int);
    int printed_chars = 0;

    (void)precision;
    (void)size;

    if (flags & F_MINUS)
        _putchar(c);

    while (printed_chars < (width - 1))
    {
        _putchar(' ');
        printed_chars++;
    }

    if (!(flags & F_MINUS))
        _putchar(c);

    return (printed_chars + 1);
}

/**
 * print_string - Print a string
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 *
 * Return: The number of characters printed
 */
int print_string(va_list list, int flags, int width, int precision)
{
    char *str = va_arg(list, char *);
    int printed_chars = 0;

    if (str == NULL)
        str = "(null)";

    if (precision == -1)
        precision = _strlen(str);

    if (flags & F_MINUS)
        printed_chars += _printnstr(str, precision);

    while (printed_chars < (width - _strlen(str)))
    {
        _putchar(' ');
        printed_chars++;
    }

    if (!(flags & F_MINUS))
        printed_chars += _printnstr(str, precision);

    return (printed_chars);
}

/**
 * print_percent - Print a percent symbol
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 *
 * Return: The number of characters printed
 */
int print_percent(va_list list, int flags)
{
    (void)list;
    (void)flags;

    _putchar('%');
    return (1);
}

/**
 * print_int - Print an integer
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier (not used)
 *
 * Return: The number of characters printed
 */
int print_int(va_list list, int flags, int width, int precision, int size)
{
    int n = va_arg(list, int);
    char *str;
    int printed_chars = 0;

    (void)size;

    if (n < 0)
    {
        n = -n;
        flags |= F_NEGATIVE;
    }

    str = _utoa(n, precision, 10);

    if (flags & F_NEGATIVE)
        str = _strconcat("-", str);

    if (flags & F_PLUS)
        str = _strconcat("+", str);

    if (flags & F_SPACE)
        str = _strconcat(" ", str);

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
