#include "main.h"
/**
 * handle_di_specifier - Handles the 'd' and 'i' format specifiers for printf.
 *
 * @format: The format string containing the specifier.
 * @args: A va_list containing the arguments for the format string.
 *
 * Return: The number of characters printed.
 */
int handle_di_specifier(const char *format, va_list args)
{
	int char_type = 0;

	if (*++format == 'l')
	{
		long num = va_arg(args, long);
		char num_str[21];
		int str_len = snprintf(num_str, sizeof(num_str), "%ld", num);

		write(1, num_str, str_len);
		char_type += str_len;
	}
	else if (*format == 'h')
	{
		short num = va_arg(args, int);
		char num_str[7];
		int str_len = snprintf(num_str, sizeof(num_str), "%hd", num);

		write(1, num_str, str_len);
		char_type += str_len;
	}
	else
	{
		int num = va_arg(args, int);
		char num_str[12];
		int str_len = snprintf(num_str, sizeof(num_str), "%d", num);

		write(1, num_str, str_len);
		char_type += str_len;
	}

	return (char_type);
}
/**
 * handle_u_specifier - Handles the 'u' format specifier for printf.
 *
 * @format: The format string containing the specifier.
 * @args: A va_list containing the arguments for the format string.
 *
 * Return: The number of characters printed.
 */
int handle_u_specifier(const char *format, va_list args)
{
	int char_type = 0;

	return (char_type);
}
