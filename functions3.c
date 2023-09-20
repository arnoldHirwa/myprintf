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

/**
 * handle_specifier - Handles the printing of characters and format specifiers
 * @specifier: The format specifier character (e.g., 'c', 's', '%', 'd', 'i', 'b', 'u', 'o', 'x', 'X', 'p')
 * @args: A va_list containing the arguments
 * @flags: Flags for formatting (e.g., '-', '0')
 * @width: Minimum field width
 * @precision: Precision specifier
 * @size: Size specifier (e.g., 'h', 'l')
 *
 * Return: The number of characters printed
 */
 
int handle_specifier(char specifier, va_list args, int flags, int width, int precision, int size)
{
    int printed_chars = 0;

    switch (specifier)
    {
        case 'c':
            printed_chars += print_char(args, flags, width, precision, size);
            break;
        case 's':
            printed_chars += print_string(args, flags, width, precision);
            break;
        case '%':
            printed_chars += print_percent(args, flags);
            break;
        case 'd':
        case 'i':
            printed_chars += print_int(args, flags, width, precision, size);
            break;
        case 'u':
            printed_chars += print_unsigned(args, flags, width, precision, size);
            break;
        case 'o':
            printed_chars += print_octal(args, flags, width, precision, size);
            break;
        case 'x':
            printed_chars += print_hexadecimal(args, flags, width, precision, size);
            break;
        case 'X':
            printed_chars += print_unsigned_hex(args, flags, width, precision, size);
            break;
        case 'b':
            printed_chars += print_binary(args, flags, width, precision, size);
            break;
        case 'p':
            printed_chars += print_pointer(args);
            break;
        default:
            return (-1);
    }

    return (printed_chars);
}
