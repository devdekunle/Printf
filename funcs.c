#include "main.h"
/**
*printString - print chain of characters
*@arguements: variadic arguements to print
*Return: number of characters printed
*/
int printString(va_list arguements)
{
	char *string;
	int i;
	/*variadic string arguements stored in string*/
	string = va_arg(arguments, char *);

	if (string == NULL)
		string = "(null)";
	/*loop through string and print each character till null  byte*/
	for (i = 0; string[i]; i++)
	{
		write(1, &string[i], 1);
	}
	/*return number of prints*/
	return (i);

}


/**
* nullCase - case where other special characters come after %
*@c: character passed as arguement
*Return: number
*/

int nullCase(char c)
{

	char afterPercent = '%';

	switch (c)
	{
		case '\n':
		/*if user wants % to show then new line*/
			write(1, &afterPercent, 1);
			write(1, &c, 1);
			return (2);
		case ' ':
			write(1, &c, 1);/*print space after % sign*/
			return (1);
		case '%':
			write(1, &c, 1);/*print % sign after %sign*/
			return (1);
		default:
		/*any other character after % sign, print % sign and the character*/
			write(1, &afterPercent, 1);
			write(1, &c, 1);
			return (2);
	}
	return (0);

}


/**
 * printChar - Function to print character
 * @arguements: Variadic arguements to print
 * Return: just 1 since is a single charcter
 */
int printChar(va_list arguements)
{
	char character; /* varaible to store charcter pulled out by va_arg */

	character = va_arg(arguements, int);
	write(1, &character, 1);
	return (1);
}

