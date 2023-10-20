#include "main.h"
/**
 * handle_u_specifier - Handle the 'u' format specifier for printf.
 * @args: List of arguments for the specifier.
 * @format: The format string that contains the specifier.
 *
 * This function handles the 'u' format specifier in the printf function.
 * It retrieves an unsigned integer from the argument list and prints it.
 * The character count is updated accordingly.
 *
 * Return: The number of characters printed.
 */
int handle_u_specifier(const char *format, va_list args)
{
	int char_type = 0;
	int width = 0;
	int str_len;
	unsigned int num;
	char num_str[12];

	if (*++format == '*')
	{
		width = va_arg(args, int);
		format++;
	}
	else
	{
		while (isdigit(*format))
		{
			width = width * 10 + (*format - '0');
			format++;
		}
	}
	num = va_arg(args, unsigned int);
	_itoa(num, num_str, 10);
	str_len = strlen(num_str);

	if (width > str_len)
	{
		int padding = width - str_len;
		int i;

		for (i = 0; i < padding; i++)
		{
			write(1, " ", 1);
			char_type++;
		}
	}
	write(1, num_str, str_len);
	char_type += str_len;
	return (char_type);
}
/**
 * handle_o_specifier - Handles the 'o' format specifier for printf.
 *
 * @format: The format string containing the specifier.
 * @args: A va_list containing the arguments for the format string.
 *
 * Return: The number of characters printed.
 */
int handle_o_specifier(const char *format, va_list args)
{
	int char_type = 0;
	int str_len;
	int width = 0;
	char oct_str[12];
	unsigned int num;

	if (*++format == '*')
	{
		width = va_arg(args, int);
		format++;
	}
	else
	{
		while (isdigit(*format))
		{
			width = width * 10 + (*format - '0');
			format++;
		}
	}
	num = va_arg(args, unsigned int);
	_itoa(num, oct_str, 8);
	str_len = strlen(oct_str);

	if (width > str_len)
	{
		int padding = width - str_len;
		int i;

		for (i = 0; i < padding; i++)
		{
			write(1, " ", 1);
			char_type++;
		}
	}
	write(1, oct_str, str_len);
	char_type += str_len;
	return (char_type);
}
/**
 * handle_x_specifier - Handles the 'x' format specifier for printf.
 *
 * @format: The format string containing the specifier.
 * @args: A va_list containing the arguments for the format string.
 *
 * Return: The number of characters printed.
 */
int handle_x_specifier(const char *format, va_list args)
{
	int i;
	int char_type = 0;
	int width = 0;
	unsigned int num;
	int str_len;
	char hex_str[8];

	if (*++format == '*')
	{
		width = va_arg(args, int);
		format++;
	}
	else
	{
		while (isdigit(*format))
		{
			width = width * 10 + (*format - '0');
			format++;
		}
	}
	num = va_arg(args, unsigned int);
	_itoa(num, hex_str, 16);
	str_len = strlen(hex_str);

	if (width > str_len)
	{
		int padding = width - str_len;

		for (i = 0; i < padding; i++)
		{
			write(1, " ", 1);
			char_type++;
		}
	}
	for (i = 0; i < str_len; i++)
	{
		hex_str[i] = tolower(hex_str[i]);
	}
	write(1, hex_str, str_len);
	char_type += str_len;
	return (char_type);
}
/**
 * handle_X_specifier - Handles the 'X' format specifier for printf.
 *
 * @format: The format string containing the specifier.
 * @args: A va_list containing the arguments for the format string.
 *
 * Return: The number of characters printed.
 */
int handle_X_specifier(const char *format, va_list args)
{
	int char_type = 0;
	int width = 0;
	char hex_str[8];
	int i;
	int str_len;
	unsigned int num;

	if (*++format == '*')
	{
		width = va_arg(args, int);
		format++;
	}
	else
	{
		while (isdigit(*format))
		{
			width = width * 10 + (*format - '0');
			format++;
		}
	}
	num = va_arg(args, unsigned int);
	_itoa(num, hex_str, 16);
	str_len = strlen(hex_str);

	if (width > str_len)
	{
		int padding = width - str_len;

		for (i = 0; i < padding; i++)
		{
			write(1, " ", 1);
			char_type++;
		}
	}
	write(1, hex_str, str_len);
	char_type += str_len;
	return (char_type);
}
