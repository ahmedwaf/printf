#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: char_type.
 */
int _printf(const char *format, ...)
{
	int char_type = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			char_type += write_character(*format);
		}
		else
		{
			format++;
			char_type += handle_format_specifier(&format, args);
		}
		format++;
	}

	va_end(args);
	return (char_type);
}
/**
 * write_character - Write a character to the standard output.
 * @c: The character to write.
 * Return: The number of characters written.
 */
int write_character(char c)
{
	return (write(1, &c, 1));
}
/**
 * handle_format_specifier - Handle a format specifier in the format string.
 * @format: A pointer to the current position in the format string.
 * @args: The variable arguments list.
 * Return: The number of characters written.
 */
int handle_format_specifier(const char **format, va_list args)
{
	int char_type = 0;

	switch (**format)
	{
		case 'c':
			char_type += write_character(va_arg(args, int));
			break;
		case 's':
			char_type += write_string(va_arg(args, char *));
			break;
		case '%':
			char_type += write_character('%');
			break;
		default:
			break;
	}

	return (char_type);
}
/**
 * write_string - Write a string to the standard output.
 * @str: The string to write.
 * Return: The number of characters written.
 */
int write_string(const char *str)
{
	int str_len = _strlen(str);

	return (write(1, str, str_len));
}
