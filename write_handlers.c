#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a character
 * @c: Character to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int handle_write_char(char a, char buffer[],
	int flags, int width, int precision, int size)
{ /* Character is stored at the left and padding at the buffer's right */
	int index = 0;
	char padding_char = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padding_char = '0';

	buffer[index++] = a;
	buffer[index] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (index = 0; index < width - 1; index++)
			buffer[BUFF_SIZE - index - 2] = padding_char;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - index - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - index - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a number
 * @is_negative: Flag indicating if the number is negative.
 * @index: Index at which the number starts in the buffer.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int write_number(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padding_char = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';

	return (write_num(index, buffer, flags, width, precision,
		length, padding_char, extra_char));
}

/**
 * write_num - Writes a number using a buffer
 * @index: Index at which the number starts on the buffer.
 * @buffer: Buffer.
 * @flags: Flags.
 * @width: Width.
 * @precision: Precision specifier.
 * @length: Number length.
 * @padding_char: Padding character.
 * @extra_char: Extra character.
 *
 * Return: Number of printed characters.
 */
int write_num(int index, char buffer[],
	int flags, int width, int precision,
	int length, char padding_char, char extra_char)
{
	int i, padd_start = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padding_char = ' '; /* width is displayed with padding ' ' */
	if (precision > 0 && precision < length)
		padding_char = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padding_char;
		buffer[i] = '\0';
		if (flags & F_MINUS && padding_char == ' ')/* Assign extra char to the left of buffer */
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padding_char == ' ')/* extra char to the left of buffer */
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padding_char == '0')/* extra char to the left of padding */
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start)));
		}
	}
	if (extra_char)
		buffer[--index] = extra_char;
	return (write(1, &buffer[index], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative.
 * @index: Index at which the number starts in the buffer.
 * @buffer: Array of characters.
 * @flags: Flags specifiers.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.

