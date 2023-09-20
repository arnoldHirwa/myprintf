#include "main.h"

/**
 * convert_size_number - Converts size flags to the corresponding int size.
 * @size: The size flag.
 * Return: The corresponding int size.
 */
int convert_size_number(int size)
{
	if (size == S_LONG)
		return (sizeof(long));
	else if (size == S_SHORT)
		return (sizeof(short));
	return (0);
}

/**
 * convert_size_unsgnd - Converts size flags to the corresponding unsigned int size.
 * @size: The size flag.
 * Return: The corresponding unsigned int size.
 */
unsigned int convert_size_unsgnd(int size)
{
	if (size == S_LONG)
		return (sizeof(unsigned long));
	else if (size == S_SHORT)
		return (sizeof(unsigned short));
	return (0);
}
