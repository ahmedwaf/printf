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

	unsigned int num = va_arg(args, unsigned int);
	char num_str[12];
	int str_len = itoa(num, num_str, 10);

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

	unsigned int num = va_arg(args, unsigned int);
	char oct_str[12];
	int str_len = itoa(num, oct_str, 8);

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
	int char_type = 0;

	unsigned int num = va_arg(args, unsigned int);
	char hex_str[8];
	int str_len = itoa(num, hex_str, 16);

	for (int i = 0; i < str_len; i++)
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

	unsigned int num = va_arg(args, unsigned int);
	char hex_str[8];
	int str_len = itoa(num, hex_str, 16);

	for (int i = 0; i < str_len; i++)
	{
		hex_str[i] = toupper(hex_str[i]);
	}
	write(1, hex_str, str_len);
	char_type += str_len;
	return (char_type);
}
