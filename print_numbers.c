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
*@arguement: variadic list
*Return: count
*/

int print_u(va_list arguement)
{
	unsigned int numArray[10]; /*array to store each integer from numArg*/
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


/**
*printBinary -convert binary to decimal
*@arguement: number to convert
*Return: count
*/
int printBinary(va_list arguement)
{
	unsigned int numarray[32], i, num, sum, varNum;
	int count;

	sum = 0;
	count = 0;

	varNum = va_arg(arguement, unsigned int);
	num = 2147483648; /* multiplying two 31 times*/
	numArray[0] = varNum / num;
	for (i = 1; i < 32; i++)
	{
		num /= 2;
		/*store remainder of division in array*/
		numArray[i] = (varNum / num) % 2;

	}
	for (i = 31; i >= 0; i--)
	{
		_putchar(numArray[i]);
		count++;

	}




	return (count);

}
