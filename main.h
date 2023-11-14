#include &lt;limits.h&gt;
#include &lt;stdio.h&gt;
#include &quot;main.h&quot;
/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
int len;
int len2;
unsigned int ui;
void *addr;
len = _printf(&quot;Let&#39;s try to printf a simple sentence.\n&quot;);
len2 = printf(&quot;Let&#39;s try to printf a simple sentence.\n&quot;);
ui = (unsigned int)INT_MAX + 1024;
addr = (void *)0x7ffe637541f0;
_printf(&quot;Length:[%d, %i]\n&quot;, len, len);
printf(&quot;Length:[%d, %i]\n&quot;, len2, len2);
_printf(&quot;Negative:[%d]\n&quot;, -762534);
printf(&quot;Negative:[%d]\n&quot;, -762534);
_printf(&quot;Unsigned:[%u]\n&quot;, ui);
printf(&quot;Unsigned:[%u]\n&quot;, ui);
_printf(&quot;Unsigned octal:[%o]\n&quot;, ui);
printf(&quot;Unsigned octal:[%o]\n&quot;, ui);
_printf(&quot;Unsigned hexadecimal:[%x, %X]\n&quot;, ui, ui);
printf(&quot;Unsigned hexadecimal:[%x, %X]\n&quot;, ui, ui);
_printf(&quot;Character:[%c]\n&quot;, &#39;H&#39;);
printf(&quot;Character:[%c]\n&quot;, &#39;H&#39;);
_printf(&quot;String:[%s]\n&quot;, &quot;I am a string !&quot;);

printf(&quot;String:[%s]\n&quot;, &quot;I am a string !&quot;);
_printf(&quot;Address:[%p]\n&quot;, addr);
printf(&quot;Address:[%p]\n&quot;, addr);
len = _printf(&quot;Percent:[%%]\n&quot;);
len2 = printf(&quot;Percent:[%%]\n&quot;);
_printf(&quot;Len:[%d]\n&quot;, len);
printf(&quot;Len:[%d]\n&quot;, len2);
_printf(&quot;Unknown:[%r]\n&quot;);
printf(&quot;Unknown:[%r]\n&quot;);
return (0);
}
