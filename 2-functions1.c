#include "main.h"
/********** PRINT UNSIGNED NUMBER **********/
/**
 * print_unsigned - prints an unsigned number
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of characters printed
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int u = va_arg(types, unsigned long int);

	u = convert_size_unsgnd(u, size);

	if (u == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (u > 0)
	{
		buffer[i--] = (u % 10) + '0';
		u /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/********** PRINT UNSIGNED NUMBER IN OCTAL **********/
/**
 * print_octal - prints an unsigned number in octal notation
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of characters printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int u = va_arg(types, unsigned long int);
	unsigned long int init_u = u;

	UNUSED(width);

	u = convert_size_unsgnd(u, size);

	if (u == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (u > 0)
	{
		buffer[i--] = (u % 8) + '0';
		u /= 8;
	}
	if (flags & F_HASH && init_u != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/********** PRINT UNSIGNED NUMBER IN HEXADECIMAL **********/
/**
 * print_hexadecimal - prints an unsigned number in hexadecimal notation
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/********** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **********/
/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal notation
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/********** PRINT HEXA NUMBER IN LOWER OR UPPER **********/
/**
 * print_hexa - prints a lower or upper hexadecimal number
 * @types: lists array of arguments
 * @map_to: array of values to map the number to
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @flag_ch: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 * @size: size specification
 * Return: number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int u = va_arg(types, unsigned long int);
	unsigned long int init_u = u;

	UNUSED(width);

	u = convert_size_unsgnd(u, size);

	if (u == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (u > 0)
	{
		buffer[i--] = map_to[u % 16];
		u /= 16;
	}
	if (flags & F_HASH && init_u != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}