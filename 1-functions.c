#include "main.h"
/********** PRINT CHAR **********/
/**
 * print_char - prints a character
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of characters printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/********** PRINT STRING **********/
/**
 * print_string - prints a string
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of characters printed
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > precision)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/********** PRINT PERCENT SIGN **********/
/**
 * print_percent - prints percent sign
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of characters printed
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/********** PRINT INT **********/
/**
 * print_int - prints integer
 * @types: lists array of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of characters printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int l = va_arg(types, long int);
	unsigned long int u;

	l = convert_size_number(l, size);

	if (l == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	u = (unsigned long int)l;

	if (l < 0)
	{
		u = (unsigned long int)((-1) * l);
		is_negative = 1;
	}

	while (u > 0)
	{
		buffer[i--] = (u % 10) + '0';
		u /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/********** PRINT BINARY **********/
/**
 * print_binary - prints an unsigned number
 * @types: lists array of arguments
 * @buffer: vuffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of characters printed
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int u, v, w, sum, a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	u = va_arg(types, unsigned int);
	v = 2 ^ (31);
	a[0] = u / v;
	for (w = 1; w < 32; w++)
	{
		v /= 2;
		a[w] = (u / v) % 2;
	}
	for (w = 0, sum = 0, count = 0; w < 32; w++)
	{
		sum += a[w];
		if (sum || w == 31)
		{
			char z = '0' + a[w];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

