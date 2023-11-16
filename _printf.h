#ifndef _PRINTF_H
#define _PRINTF_H

#include "main.h"

/**
 * enum PrintfState - Contains the different states that
 * _printf can be in
*/
typedef enum
{
	NORMAL = 0, FLAG, LENGTH, SHORT, LONG, SPEC
} PrintfState;

/**
 * enum PrintfLengthState - Contains the different length states that
 * _printf can be in
*/
typedef enum
{
	LEN_DEFAULT = 10, LEN_SHORT_SHORT, LEN_SHORT, LEN_LONG, LEN_LONG_LONG
} PrintfLengthState;

uint8_t PrintfNum(uint64_t arg, uint8_t length,
					bool sign, uint8_t base, bool hexUpper);

void PrintfSpecifierParser(int *countPtr, uint16_t i, const char *specifier,
	va_list arguments, uint8_t base, bool sign,
	PrintfLengthState length, bool hexUpper);


#endif
