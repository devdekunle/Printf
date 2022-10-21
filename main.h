#ifndef MAIN_H
#define MAIN_H

#include <unistd.h> /*for the write function*/
#include <stdarg.h>/*for variadic macros*/
#include <stdio.h>

struct link
{
	char ch;
	int (*funcPointer)(va_list);

};
typedef struct link SL;

/*pointer protoypes*/
int print_hex(unsigned int n, unsigned int c);
int print_o(va_list o);
int print_x(va_list x);
int print_X(va_list X);
/*static unsigned long _pow(unsigned int base, unsigned int exponent);*/
int print_p(va_list arguement);
int _putchar(char c);
int printChar(va_list arguement);
int printString(va_list arguement);
int nullCase(char c);
int (*selectFunc(char s))(va_list);
int _printf(const char *format, ...);
int print_rev_string(va_list arguement);
int printrot13(va_list arguement);
int printNumber(va_list arguement);
int print_u(va_list arguement);
int printBinary(va_list arguement);
#endif
