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
int printChar(va_list arguement);
int printString(va_list arguement);
int nullCase(char c);
int (*selectFunc(char s))(va_list);
int _printf(const char *format, ...);
int print_rev_string(va_list arguement);
int printrot13(va_list arguement);
int printNumber(va_list arguement);
#endif
