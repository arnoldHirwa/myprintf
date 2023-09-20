#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct format - struct for format specifiers
 * @fmt: The format specifier (e.g., 'c', 's', 'd', 'x', etc.)
 * @fn: The function to handle the format specifier
 */
typedef struct format
{
    char fmt;
    int (*fn)(va_list, char *, int, int, int, int);
} fmt_t;

/* Format Specifier Flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Size Flags */
#define S_SHORT 1
#define S_LONG 2

/* Additional Size Flags */
#define SIZE_NONE 0
#define S_CHAR 4
#define S_LONG_LONG 8
#define S_LONG_DOUBLE 16
#define F_NEGATIVE 32
#define F_UPPERCASE 64
#define BUFF_SIZE 1024

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int handle_print(const char *format, va_list args);
int handle_specifier(char c, va_list args, int flags, int width, int precision, int size);
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
int write_char(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_string(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_percent(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_int(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_unsigned(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_octal(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_hexadecimal(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_hexa_upper(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_binary(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_pointer(int ind, char buffer[], int flags, int width, int precision, void *pointer);
int write_non_printable(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_reverse(va_list list, char buffer[], int flags, int width, int precision, int size);
int write_rot13string(va_list list, char buffer[], int flags, int width, int precision, int size);
int get_unsigned_arg(va_list args, int size);
char *_utoa(unsigned int n, int precision, int base);
int _printnstr(char *str, int len);
char *_strrev(char *str);
char *_strconcat(const char *s1, const char *s2);
int get_int_arg(va_list args, int size);
int _strlen(const char *str);
int convert_size_number(int size);
unsigned int convert_size_unsgnd(int size);
int get_size(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_flags(const char *format, int *index);
int write_num(int ind, char buffer[], int flags, int width, int precision, long int num);
int write_unsgnd_num(int ind, char buffer[], int flags, int width, int precision, unsigned int num, int base);
int is_digit(int c);

#endif /* MAIN_H */
