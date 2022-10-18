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
	string = va_arg(arguements, char *);

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

/**
 * print_rev_string - print string in reverse
 * @arguements: variadic arguements to print
 * Return: Numbers of characters printed
 */
int print_rev_string(va_list arguements)
{
	char *string;/*to store string pulled out by va_arg*/
	int num = 0;/*to store number of characters printed in reverse*/
	int i, j;

	string = va_arg(arguements, char *);
	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i]; i++)/*get string lenght*/
		;
	/*loop through string from end and write each charcter out in reverse*/
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &string[j], 1);
		num++;
	}
	return (num);/*return total number of characters*/
}

/**
 * printrot13 - Replace a char with another char which is at number 13 away
 * @arguements: varaidic arguement to print
 * Return: total number of characters printed out by write
 */
int printrot13(va_list arguements)
{
	char *string;/*varaible to store string pulled out by va_arg */
	unsigned int i, j;
	int count = 0;/*to count number of char writed to output by write */
	/**
	 * each char in c1 is a rot13 of each char in c2 in same position
	 * example, A is to N, R is to E, m is to z and so on...
	 */
	char c1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(arguements, char *);
	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i]; i++)/*check weather is a character*/
	{
		for (j = 0; c1[j]; j++)
		{
			/*if char in string is same as char in c1*/
			if (string[i] == c1[j])
			{
				/*write out is equivalent rot13 in c2 */
				write(1, &c2[j], 1);
				count++;/*and icrease count by 1 */
				break;
			}
		}
		/**
		 * Even if the char in string does not match any char in c2
		 * write it out and increase count by 1 since we need total
		 * count
		 */
		if (!c1[j])
		{
			write(1, &string[i], 1);
			count++;
		}
	}
	return (count);/*return total count after everthying */
}



