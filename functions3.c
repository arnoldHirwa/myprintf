#include "main.h"
#include "utils.c"

/**
 * print_binary - Print a binary number
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: The number of characters printed
 */
int print_binary(va_list list, int flags, int width, int precision, int size)
{
    unsigned int u = get_unsigned_arg(list, size);
    char *str;
    int printed_chars = 0;

    /* Unused parameter */
    (void)precision;

    str = _utoa(u, precision, 2);

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
 * print_unsigned_octal - Print an unsigned octal number
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: The number of characters printed
 */
int print_unsigned_octal(va_list list, int flags, int width, int precision, int size)
{
    unsigned int u = get_unsigned_arg(list, size);
    char *str;
    int printed_chars = 0;

    (void)precision;

    str = _utoa(u, precision, 8);

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
 * print_unsigned_hex - Print an unsigned hexadecimal number
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: The number of characters printed
 */
int print_unsigned_hex(va_list list, int flags, int width, int precision, int size)
{
    unsigned int u = get_unsigned_arg(list, size);
    char *str;
    int printed_chars = 0;
    char prefix = '\0';

    (void)precision;

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

/**
 * print_reverse - Print a reversed string
 * @list: A va_list containing the arguments
 * @flags: Flags to modify the output
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: The number of characters printed
 */
int print_reverse(va_list list, int flags, int width, int precision, int size)
{
    char *str = va_arg(list, char *);
    int printed_chars = 0;

    (void)precision;
    (void)size;

    if (str == NULL)
        str = "(null)";

    str = _strrev(str);

    if (flags & F_MINUS)
        printed_chars += _printnstr(str, _strlen(str));

    while (printed_chars < (width - _strlen(str)))
    {
        _putchar(' ');
        printed_chars++;
    }

    if (!(flags & F_MINUS))
        printed_chars += _printnstr(str, _strlen(str));

    return (printed_chars);
}
