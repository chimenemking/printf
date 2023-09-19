#include "main.h"
/**
 * printf - to print output to stdout
 * @format: format string containing conversion specifiers
 * Return: return the number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int p, count_str, chars_print = 0;
	va_list list_arguments;

	va_start(list_arguments, format);
	for (p = 0; format[p] != '\0'; p++)
	{
		if (format[p] != '%')
		{
			put_car(format[p]);
		}
		else if (format[p + 1] == 'c')
		{
			put_car(va_arg(list_arguments, int));
			p++;
		}
		else if (format[p + 1] == 's')
		{
			count_str = put_ss(va_arg(list_arguments, char *));
			p++;
			chars_print = chars_print + (count_str - 1);
		}
		else if (format[p + 1] == '%')
		{
			put_car('%');
		}
		chars_print++;
	}
	va_end(list_arguments);
	return (chars_print);
}
