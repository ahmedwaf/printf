#include "main.h"
/**
 * get_width - Extracts the field width from the format string.
 *
 * @format: The format string.
 * @i: Pointer to the current position in the format string.
 * @args: The variable arguments list.
 *
 * Return: The field width or -1 if not specified.
 */
int get_width(const char *format, int *i, va_list args)
{
	int curr_i = *i + 1;
	int width = -1;
	bool is_specifier_found = false;

	while (format[curr_i] != '\0')
	{
		if (_isdigit(format[curr_i]))
		{
			if (!is_specifier_found)
			{
				is_specifier_found = true;
				width = 0;
			}
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			if (!is_specifier_found)
			{
				is_specifier_found = true;
				width = va_arg(args, int);
			}
			break;
		}
		else
		{
			break;
		}
		curr_i++;
	}

	*i = curr_i - 1;

	return (width);
}
