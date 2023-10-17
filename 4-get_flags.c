#include "main.h"
/**
 * get_flags - calculates active flags
 * @format: formatted string where the argument is printed
 * @i: takes a parameter
 *
 * Return: flag
 */
int get_flags(const char *format, int *i)
{
	int new_i, j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (new_i = *i + 1; format[new_i] != '\0'; new_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[new_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = new_i - 1;

	return (flags);
}
