#include "main.h"

/**
 * _printf - print output to stdout
 * @format: format string containing conversion specifiers
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int chars_printed = 0;
	va_list list_arguments;

	if (!format)
	return (-1);

	va_start(list_arguments, format);
	while (*format)
	{
	if (*format != '%')
	{
		chars_printed += put_car(*format);
	}
	else
	{
	format++;
		if (*format == '\0')
			break;
		if (*format == '%')
		{
			chars_printed += put_car(*format);
		}
		else if (*format == 'c')
		{
			chars_printed += print_char(list_arguments);
		}
		else if (*format == 's')
		{
			chars_printed += print_string(list_arguments);
		}
		else if (*format == '%')
		{
			chars_printed += print_percent();
		}
	}
	format++;
	}
	va_end(list_arguments);
	return (chars_printed);
}

/**
 * print_char - print a character
 * @list: va_list with the character to print
 * Return: number of characters printed
 */
int print_char(va_list list)
{
	char ch = va_arg(list, int);

	return (put_car(ch));
}

/**
 * print_string - print a string
 * @list: va_list with the string to print
 * Return: number of characters printed
 */
int print_string(va_list list)
{
	const char *str = va_arg(list, const char *);
	int chars_printed = 0;

	while (*str)
	{
		put_car(*str);
		str++;
		chars_printed++;
	}
	return (chars_printed);
}

/**
 * print_percent - print a percent sign
 * Return: 1 (for the percent character)
 */
int print_percent(void)
{
	return (put_car('%'));
}
