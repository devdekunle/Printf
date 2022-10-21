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
	unsigned int numArray[32], i, num, sum, varNum;
	int count;


	varNum = va_arg(arguement, unsigned int);
	num = 2147483648; /* multiplying two 31 times*/
	numArray[0] = varNum / num;
	for (i = 1; i < 32; i++)
	{
		num /= 2;
		/*store remainder of division in array*/
		numArray[i] = (varNum / num) % 2;

	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += numArray[i];
		if (sum || i == 31)
		{
			_putchar(numArray[i] + '0');
			count++;
		}
	}




	return (count);

}
/**
 * print_o - takes an unsigned int and prints it in octal notation
 * @o: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_o(va_list o)
{
	unsigned int a[11];
	unsigned int i, m, n, sum;
	int count;

	n = va_arg(o, unsigned int);
	m = 1073741824; /* (8 ^ 10) */
	a[0] = n / m;
	for (i = 1; i < 11; i++)
	{
		m /= 8;
		a[i] = (n / m) % 8;
	}
	for (i = 0, sum = 0, count = 0; i < 11; i++)
	{
		sum += a[i];
		if (sum || i == 10)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
