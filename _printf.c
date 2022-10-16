#include "main.h"
/**
*_printf - custom function to print formatted data
*@format: format specifier string
*Return: totalPrints
*/
int _printf(const char *format, ...)
{
	va_list arguements; /*declare variadic list*/
	int totalPrints = 0;
	int i = 0;
	int (*f)(va_list);

	va_start(arguements, format); /*initailize variadic list*/

	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{	i++;/*go to next character after finding % sign*/
		/*pass the character to select function for specifer*/
			f = selectFunc(format[i]);
			if (f == NULL)
				/*pass character to function for case where no specifier*/
				totalPrints += nullCase(format[i]);
			else
				totalPrints += f(arguements);/*pass selected function variadic list*/
		}
		else if (format[i] == '%' && format[i] == '\0')
		{
			return (-1);/*error if charcter after % is '\0'*/

		}

		else
		{
			/*print string literal if no % till null byte and add to total*/
			write(1, &format[i], 1);
			totalPrints++;
		}
		i++;
	}
	va_end(arguements);
	return (totalPrints);
}
