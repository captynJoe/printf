#include "main.h"

void flush_buffer(char buffer[], int *buffer_index);

/**
 * custom_printf - Custom printf function
 * @format: Format string.
 * Return: Number of characters printed.
 */
int custom_printf(const char *format, ...)
{
    int index, printed_chars = 0, total_printed = 0;
    int flags, width, precision, size, buffer_index = 0;
    va_list args;
    char output_buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (index = 0; format && format[index] != '\0'; index++)
    {
        if (format[index] != '%')
        {
            output_buffer[buffer_index++] = format[index];
            if (buffer_index == BUFF_SIZE)
                flush_buffer(output_buffer, &buffer_index);

            printed_chars++;
        }
        else
        {
            flush_buffer(output_buffer, &buffer_index);
            flags = get_flags(format, &index);
            width = get_width(format, &index, args);
            precision = get_precision(format, &index, args);
            size = get_size(format, &index);
            ++index;
            printed_chars = handle_print(format, &index, args, output_buffer,
                                         flags, width, precision, size);
            if (printed_chars == -1)
                return (-1);
            total_printed += printed_chars;
        }
    }

    flush_buffer(output_buffer, &buffer_index);

    va_end(args);

    return (total_printed);
}

/**
 * flush_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * @buffer_index: Index at which to add the next character, represents the length.
 */
void flush_buffer(char buffer[], int *buffer_index)
{
    if (*buffer_index > 0)
        write(1, &buffer[0], *buffer_index);

    *buffer_index = 0;
}

