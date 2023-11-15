#include "main.h"

/**
 * selector - selects the appropriate specifiers
 * @args: number of arguements
 * @printed: the printed characters
 * @format: the format specifier
 * Return: printed charcaters
 */

int selector(const char *format, va_list args, int printed)
{
	switch (*format)
	{
		case 'd':
		case 'i':
			printed = print_integer(args, printed);
			break;
		case 'c':
			_putchar(va_arg(args, int));
			printed++;
			break;
		case 's':
			printed = print_string(args, printed);
			break;
		case '%':
			_putchar('%');
			printed++;
			break;
		case 'b':
			printed = print_binary(va_arg(args, unsigned int), printed);
			break;
		default:
			break;
	}
	return (printed);
}
