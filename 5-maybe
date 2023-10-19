#include "main.h"
/**
 * get_precision - calculates the precision for printing
 * @format: formatted string in which the arguments are to be printed
 * @i: list of arguments to be printed
 * @list: list of arguments
 *
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int new_i = *i + 1;
	int precision = -1;

	if (format[new_i] != '.')
		return (precision);

	precision = 0;

	for (new_i += 1; format[new_i] != '\0'; new_i++)
	{
		if (is_digit(format[new_i]))
		{
			precision *= 10;
			precision += format[new_i] - '0';
		}
		else if (format[new_i] == '*')
		{
			new_i++;
			precision = va_args(list, int);
			break;
		}
		else
			break;
	}

	*i = new_i - 1;

	return (precision);
}
