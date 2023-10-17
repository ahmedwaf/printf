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
			write(1, format, 1);
			char_type++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':{
					  char c = va_arg(args, int);
						write(1, &c, 1);
						char_type++;
						break;
						}
				case 's':{
						char *str = va_arg(args, char *);
						int str_len = strlen(str);

						write(1, str, str_len);
						char_type += str_len;
						break;
						}
				case '%':{
						write(1, "%", 1);
						char_type++;
						break;
						}
				default:{
						break;
						}
			}
		format++;
	}
	va_end(args);
	return (char_type);
}
