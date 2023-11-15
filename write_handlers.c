#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	char flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	char a = ' ';
	int i = 0;

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		a = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = a;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	char flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buff
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @length: length of the buffer
 * @padd: padding character
 * @extra_ch: extra character
 *
 * Return: Number of chars printed.
 */
int write_num(int ind, char buffer[], char flags,
	int width, int precision, int length, char padd, char extra_ch)
{
	int i = 0, j = 0, k = 0, l = 0;
	char tmp[BUFF_SIZE] = {0};

	if (precision == 0 && buffer[ind] == '0')
	{
		buffer[ind] = '\0';
		return (0);
	}
	if (precision == 0 && buffer[ind] == '\0')
		return (0);
	if (precision > length - ind)
	{
		precision = length - ind;
		flags &= ~F_ZERO;
	}
	tmp[0] = extra_ch;
	if (flags & F_MINUS)
		tmp[++i] = extra_ch;
	while (i < width - MAX(precision, length - ind))
		tmp[++i] = padd;
	if (!(flags & F_MINUS))
		tmp[++i] = extra_ch;
	j = i;
	while (j < width - precision)
		tmp[++j] = '0';
	k = ind;
	while (j < width)
		tmp[++j] = buffer[k++];
	tmp[++j] = '\0';
	while (i < length)
		buffer[l++] = tmp[i++];
	buffer[l] = '\0';
	return (l);
}

