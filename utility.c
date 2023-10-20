#include "main.h"

/**
 * _strlen - Calculate the length of a string.
 * @str: The string to measure.
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _isdigit - Check if a character is a digit.
 * @c: The character to check.
 * Return: 1 if it's a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _itoa - Convert an integer to a string.
 * @n: The integer to convert.
 * @str: The buffer to store the result.
 * @base: The base for the conversion (e.g., 10 for decimal).
 * Return: A pointer to the resulting string.
 */
int _itoa(int n, char *str, int base)
{
	int i = 0;
	int isNegative = 0;
	int start = 0;
	int end = i - 1;

	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (i);
	}

	if (n < 0 && base != 10)
	{
		isNegative = 1;
		n = -n;
	}

	while (n != 0)
	{
		int rem = n % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		n /= base;
	}

	if (isNegative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

	return (i);
}
/**
 * write_string_special - Write a string with non-printable characters.
 * @str: The string to write.
 * Return: The number of characters written.
 */
int write_string_special(char *str)
{
	int char_type = 0;

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			char_type += write(1, "\\x", 2);
			char_type += write_hex_value(*str);
		}
		else
		{
			char_type += write_character(*str);
		}
		str++;
	}

	return (char_type);
}

/**
 * write_hex_value - Write the ASCII code value in hexadecimal.
 * @value: The ASCII code value.
 * Return: The number of characters written.
 */
int write_hex_value(char value)
{
	char hex_chars[] = "0123456789ABCDEF";
	char hex[3];

	hex[0] = hex_chars[((value >> 4) & 0xF)];
	hex[1] = hex_chars[(value & 0xF)];
	hex[2] = '\0';
	return (write(1, hex, 2));
}
