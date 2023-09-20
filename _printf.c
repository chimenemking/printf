#include "main.h"
/**
 * _printf - to print output to stdout
 * @format: format string containing conversion specifiers
 * Return: return the number of characters printed
 */
int _printf(const char *format, ...)
{
	int chars_print = 0;
	va_list list_arguments;

	va_start(list_arguments, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chars_print++;
		} else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == '%')
			{
				write(1, format, 1);
				chars_print++;
			} else if (*format == 'c')
			{
				char ch = va_arg(list_arguments, int);

				write(1, &ch, 1);
				chars_print++;
			} else if (*format == 's')
			{
				char *str = va_arg(list_arguments, char*);

				int strln = strlen(str);

				chars_print += write(1, str, strln);
			}
		} format++;
	}
	va_end(list_arguments);
	return (chars_print);
}
