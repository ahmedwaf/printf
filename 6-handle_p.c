#include "main.h"
/**
 * handle_p_specifier - Handles the 'p' format specifier for printf.
 *
 * @format: The format string containing the specifier.
 * @args: A va_list containing the arguments for the format string.
 *
 * Return: The number of characters printed.
 */

int handle_p_specifier(va_list args)
{
	int char_type = 2;

	void *ptr = va_arg(args, void*);
	unsigned long ptr_val = (unsigned long) ptr;
	char ptr_str[19];
	int str_len = _itoa(ptr_val, ptr_str, 16);

	write(1, "0x", 2);
	write(1, ptr_str, str_len);
	char_type += str_len;

	return (char_type);
}
