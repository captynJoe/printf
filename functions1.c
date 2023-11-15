#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int a = BUFF_SIZE - 2;
    unsigned long int num_val = va_arg(types, unsigned long int);

    num_val = convert_size_unsigned(num_val, size);

    if (num_val == 0)
        buffer[a--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num_val > 0)
    {
        buffer[a--] = (num_val % 10) + '0';
        num_val /= 10;
    }

    a++;

    return (write_unsigned(0, a, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int a = BUFF_SIZE - 2;
    unsigned long int num_val = va_arg(types, unsigned long int);
    unsigned long int init_num_val = num_val;

    UNUSED(width);

    num_val = convert_size_unsigned(num_val, size);

    if (num_val == 0)
        buffer[a--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num_val > 0)
    {
        buffer[a--] = (num_val % 8) + '0';
        num_val /= 8;
    }

    if (flags & F_HASH && init_num_val != 0)
        buffer[a--] = '0';

    a++;

    return (write_unsigned(0, a, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    return (print_hex(types, "0123456789abcdef", buffer,
        flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hex_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hex_upper(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    return (print_hex(types, "0123456789ABCDEF", buffer,
        flags, 'X', width, precision, size));
}

/************** PRINT HEX NUMBER IN LOWER OR UPPER **************/
/**
 * print_hex - Prints a hexadecimal number in lower or upper case
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hex(va_list types, char map_to[], char buffer[],
    int flags, char flag_ch, int width, int precision, int size)
{
    int a = BUFF_SIZE - 2;
    unsigned long int num_val = va_arg(types, unsigned long int);
    unsigned long int init_num_val = num_val;

    UNUSED(width);

    num_val = convert_size_unsigned(num_val, size);

    if (num_val == 0)
        buffer[a--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num_val > 0)
    {
        buffer[a--] = map_to[num_val % 16];
        num_val /= 16;
    }

    if (flags & F_HASH && init_num_val != 0)
    {
        buffer[a--] = flag_ch;
        buffer[a--] = '0';
    }

    a++;

    return (write_unsigned(0, a, buffer, flags, width, precision, size));
}

