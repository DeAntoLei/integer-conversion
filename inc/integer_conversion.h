/* integer_conversion,h */
#ifndef INTEGER_CONVERSION_H
#define INTEGER_CONVERSION_H

#include <stdint.h>
#include <stdio.h>

// Supported integer data types (the library only supports unsigned integers)
typedef enum {
	TYPE_CHAR,		  // 1-byte
	TYPE_SHORT,		  // 2-byte
	TYPE_LONG,		  // 4-byte
	TYPE_LONG_LONG	  // 8-byte
} IntValueType;

// COnversion functions
void   convert_char(uint8_t val, uint8_t output[3]);
void   convert_short(uint16_t val, uint8_t output[3]);
size_t convert_long(const void *val, IntValueType type, uint8_t (*output)[3]);
