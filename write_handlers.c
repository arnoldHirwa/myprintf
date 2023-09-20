#include "main.h"

/**
 * handle_write_char - Writes a character to the buffer.
 * @buffer: The buffer to write to.
 * @ind: The current index in the buffer.
 * @c: The character to write.
 */
void handle_write_char(char buffer[], int *ind, char c)
{
	if (*ind == BUFF_SIZE - 1)
	{
		write(1, buffer, BUFF_SIZE - 1);
		*ind = 0;
	}

	buffer[*ind] = c;
	(*ind)++;
}

/**
 * write_number - Writes a number to the buffer.
 * @ind: The current index in the buffer.
 * @buffer: The buffer to write to.
 * @flags: The formatting flags.
 * @width: The minimum width.
 * @precision: The precision (number of digits to print).
 * @num: The number to write.
 */
int write_number(int ind, char buffer[], int flags, int width, int precision, long int num)
{
	int count = 0;
	int neg = 0;
	int padd = ' ';

	if (num < 0)
	{
		num *= -1;
		neg = 1;
	}

	if ((flags & F_PLUS) && !neg)
	{
		handle_write_char(buffer, &ind, '+');
		count++;
	}
	else if ((flags & F_SPACE) && !neg)
	{
		handle_write_char(buffer, &ind, ' ');
		count++;
	}

	if (neg)
		handle_write_char(buffer, &ind, '-');

	while (width-- > 0)
	{
		if (flags & F_ZERO)
			padd = '0';

		handle_write_char(buffer, &ind, padd);
		count++;
	}

	while (precision-- > 0)
	{
		handle_write_char(buffer, &ind, '0');
		count++;
	}

	if (num == 0 && precision == 0)
		return (count);

	if (num < 10)
		handle_write_char(buffer, &ind, num + '0');
	else
		count += write_num(ind, buffer, flags, width, precision, num / 10);

	handle_write_char(buffer, &ind, num % 10 + '0');
	return (count);
}

/**
 * write_num - Writes a number to the buffer (recursive).
 * @ind: The current index in the buffer.
 * @buffer: The buffer to write to.
 * @flags: The formatting flags.
 * @width: The minimum width.
 * @precision: The precision (number of digits to print).
 * @num: The number to write.
 * Return: The number of characters written.
 */
int write_num(int ind, char buffer[], int flags, int width, int precision, long int num)
{
	int count = 0;

	if (num < 0)
		return (0);

	if (num < 10)
	{
		handle_write_char(buffer, &ind, num + '0');
		count++;
	}
	else
	{
		count += write_num(ind, buffer, flags, width, precision, num / 10);
		handle_write_char(buffer, &ind, num % 10 + '0');
		count++;
	}

	return (count);
}

/**
 * write_unsgnd - Writes an unsigned number to the buffer.
 * @ind: The current index in the buffer.
 * @buffer: The buffer to write to.
 * @flags: The formatting flags.
 * @width: The minimum width.
 * @precision: The precision (number of digits to print).
 * @num: The unsigned number to write.
 * Return: The number of characters written.
 */
int write_unsgnd(int ind, char buffer[], int flags, int width, int precision, unsigned long int num)
{
	int count = 0;
	int padd = ' ';

	if ((flags & F_PLUS) || (flags & F_SPACE))
		padd = '0';

	while (width-- > 0)
	{
		handle_write_char(buffer, &ind, padd);
		count++;
	}

	while (precision-- > 0)
	{
		handle_write_char(buffer, &ind, '0');
		count++;
	}

	if (num == 0 && precision == 0)
		return (count);

	if (num < 10)
		handle_write_char(buffer, &ind, num + '0');
	else
		count += write_unsgnd(ind, buffer, flags, width, precision, num / 10);

	handle_write_char(buffer, &ind, num % 10 + '0');
	return (count);
}

/**
 * write_pointer - Writes a pointer address to the buffer.
 * @ind: The current index in the buffer.
 * @buffer: The buffer to write to.
 * @flags: The formatting flags.
 * @width: The minimum width.
 * @precision: The precision (number of digits to print).
 * @pointer: The pointer address to write.
 * Return: The number of characters written.
 */
int write_pointer(int ind, char buffer[], int flags, int width, int precision, void *pointer)
{
	unsigned long int num = (unsigned long int)pointer;
	int count = 0;

	handle_write_char(buffer, &ind, '0');
	handle_write_char(buffer, &ind, 'x');
	count += 2;

	if (num == 0 && precision == 0)
		return (count);

	return (count + write_unsgnd(ind, buffer, flags, width, precision, num));
}
