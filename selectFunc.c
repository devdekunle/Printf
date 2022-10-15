#include "main.h"
/**
 * selectFunc - select appropriate function to print passed argument
 * @s: character to check
 * Return: pointer to function
 */

int (*selectFunc(char s))(va_list)
{
	SL linkin[] = {
		{'c', printChar},
		{'s', printString},
		{'\0', NULL} /*for case where no match is found*/
	};
	int i = 0;

	while (linkin[i] != '\0')
	{
		if (linkin[i].ch == s)/*return pointer to function if s == ch*/
		{
			return (linkin[i].funcPointer);
		}
		i++;
	}
	return (linkin[i].funcPointer);
}
