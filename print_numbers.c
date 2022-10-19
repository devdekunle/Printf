#include "main.h"
/**
*printNumber - print integers
*@arguement: variadic list to print number from
*Return: number of characters and numbers printed
*/

int printNumber(va_list arguement)
{
	int numArray[10]; /*array to store each integer dissected from numArg*/
	int i, maxDiv, numArg, count, sum;

	count = 0;
	numArg = va_arg(arguement, int); /*assume numArg is INT_MAX*/
	maxDiv = 1000000000; /*number to divide INT_MAX to get 1st digit in INT_MAX*/
	numArray[0] = numArg / maxDiv; /*store the first character from INT_MAX*/
	for (i = 1; i < 10; i++) /*loop through INT_MAX*/
	{
		maxDiv = maxDiv / 10; /*reduce number to divide remainder of numArg*/
		numArray[i] = (numArg / maxDiv) % 10;

	}
	if (numArg < 0)
	{
		_putchar('-');
		count++; /*count the - sign*/
		for (i = 0; i < 10; i++)
			numArray[i] = numArray[i] * -1;
	}
	for (i = 0, sum = 0; i < 10; i++)
	{
		sum += numArray[i];
		if (i == 9 || sum != 0)
		{
			_putchar(numArray[i] + '0'); /*print each stored character*/
			count++;

		}

	}

	return (count);




}

/**
*print_u - print unsigned integers
*@ arguement: variadic list
*Return: count
*/

int print_u(va_list arguement)
{
	unsigned int numArray[10]; /*array to store each integer dissected from numArg*/
	unsigned int i, maxDiv, numArg, sum;
	int count;

	count = 0;
	numArg = va_arg(arguement, unsigned int); /*assume numArg is INT_MAX*/
	maxDiv = 1000000000; /*number to divide INT_MAX to get 1st digit in INT_MAX*/
	numArray[0] = numArg / maxDiv; /*store the first character from INT_MAX*/
	for (i = 1; i < 10; i++) /*loop through INT_MAX*/
	{
		maxDiv = maxDiv / 10; /*reduce number to divide remainder of numArg*/
		numArray[i] = (numArg / maxDiv) % 10;

	}
	for (i = 0, sum = 0; i < 10; i++)
	{
		sum += numArray[i];
		if (i == 9 || sum != 0)
		{
			_putchar(numArray[i] + '0'); /*print each stored character*/
			count++;

		}

	}

	return (count);




}
