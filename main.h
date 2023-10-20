#ifndef MAIIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 * @fmt: the format
 * @fn: the function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: the format
 * @fm_t: the function associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precison, int size);
/* 0-printf.c */
int _printf(const char *format, ...);
int write_character(char c);
int handle_format_specifier(const char **format, va_list args);
int write_string(const char *str);
/* 1-functions.c */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
/* 2-functions1.c */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);
/* 3-handle_print.c */
int handle_x_specifier(const char *format, va_list args);
int handle_X_specifier(const char *format, va_list args);
/* 4-get_flags */
int get_flags(const char *format, int *i);
/* 5-handle_print.c */
int _printf(const char *format, ...);
int write_character(char c);
int handle_format_specifier(const char **format, va_list args);
int write_string(const char *str);
/* 6-handle_p.c */
int handle_p_specifier(va_list args);
/* 8-get_size.c */
int handle_di_specifier(const char *format, va_list args);
int handle_u_specifier(const char *format, va_list args);
/* 9-get_width.c */
int get_width(const char *format, int *i, va_list args);
/* 10-handlers.c */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width,
		int prec, int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start);
/* utility.c */
int _strlen(const char *str);
int _isdigit(int c);
int _itoa(int n, char *str, int base);
int write_string_special(char *str);
int write_hex_value(char value);

#endif
