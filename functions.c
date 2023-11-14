#include &quot;main.h&quot;
/************************* PRINT CHAR *************************/
/**
* print_char - Prints char in project
* @types: Lists of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates all active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, flags, width, precision,
size));

}
/************************* PRINT A STRING *************************/
/**
* print_string - Prints a string
* @types: Lists of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, i;
char *str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = &quot;(null)&quot;;
if (precision &gt;= 6)
str = &quot; &quot;;
}
while (str[length] != &#39;\0&#39;)
length++;
if (precision &gt;= 0 &amp;&amp; precision &lt; length)
length = precision;
if (width &gt; length)
{
if (flags &amp; F_MINUS)
{
write(1, &amp;str[0], length);
for (i = width - length; i &gt; 0; i--)
write(1, &quot; &quot;, 1);
return (width);
}
else
{
for (i = width - length; i &gt; 0; i--)
write(1, &quot; &quot;, 1);
write(1, &amp;str[0], length);
return (width);
}
}
return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN
*************************/
/**
* print_percent - Prints a percent sign
* @types: Lists of the arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, &quot;%%&quot;, 1));
}
/************************* PRINT INT *************************/
/**
* print_int - Prints int
* @types: The lists of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates the active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);
if (n == 0)
buffer[i--] = &#39;0&#39;;
buffer[BUFF_SIZE - 1] = &#39;\0&#39;;
num = (unsigned long int)n;
if (n &lt; 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}

while (num &gt; 0)
{
buffer[i--] = (num % 10) + &#39;0&#39;;
num /= 10;
}
i++;
return (write_number(is_negative, i, buffer, flags, width,
precision, size));
}
/************************* PRINT BINARY *************************/
/**
* print_binary - Prints an unsigned number in project
* @types: The lists of arguments
* @buffer: Buffer arrays to handle print
* @flags: Calculates the active flags
* @width: get width.
* @precision:Specifications of precisions
* @size: Size specifier
* Return: Numbers of char printed.
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int count;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
n = va_arg(types, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i &lt; 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, count = 0; i &lt; 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = &#39;0&#39; + a[i];
write(1, &amp;z, 1);
count++;
}
}
return (count);
}
