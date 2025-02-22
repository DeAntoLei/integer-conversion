/* test_integer_conversion_universal.c */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../inc/integer_conversion.h"

// Helper function to print n-byte arrays
void print_byte_arrays(const uint8_t *arrays, int array_count, int n)
{
	for (int i = 0; i < array_count; i++) {
		printf("Array %d: ", i);
		for (int j = 0; j < n; j++) {
			printf("%02X ", arrays[i * n + j]);
		}
		printf("\n");
	}
}

// Function to calculate the number of n-byte arrays required
int calculate_array_count(IntValueType type, int n)
{
	int int_size_bits;
	switch (type) {
	case TYPE_CHAR:
		int_size_bits = 8;	  // 1 byte = 8 bits
		break;
	case TYPE_SHORT:
		int_size_bits = 16;	   // 2 bytes = 16 bits
		break;
	case TYPE_LONG:
		int_size_bits = 32;	   // 4 bytes = 32 bits
		break;
	case TYPE_LONG_LONG:
		int_size_bits = 64;	   // 8 bytes = 64 bits
		break;
	default:
		return 0;
	}

	double array_count_double = (double)int_size_bits / (n * 8);
	int	   array_count		  = (int)array_count_double;
	if (array_count_double > array_count) {
		return array_count + 1;	   // Round up if x has a fractional part
	}

	return array_count;
}

int main()
{
	// Example values
	uint8_t *byte_arrays;	 // Pointer to dynamically allocated byte_arrays
	int		 n;				 // byte array size in bytes

	// Convert a char (1-byte) value into 2-byte arrays
	uint8_t char_val = 0xAB;
	n				 = 2;	 // Array size in bytes
	int array_count	 = calculate_array_count(TYPE_CHAR, n);
	byte_arrays		 = malloc(array_count * n * sizeof(unsigned char));	   // Allocate memory
	if (byte_arrays == NULL) {
		printf("Error: Memory allocation failed\n");
		return 1;
	}
	convert_into_nbyte_arrays(&char_val, TYPE_CHAR, byte_arrays, n);
	printf("Coverted char value 0x%02X into %d-byte arrays:\n", char_val, n);
	print_byte_arrays(byte_arrays, array_count, n);
	free(byte_arrays);	  // Free allocated memory

	// Convert a short (2-byte) value into 3-byte arrays
	uint16_t short_val = 0xABCD;
	n				   = 3;	   // Array size in bytes
	array_count		   = calculate_array_count(TYPE_SHORT, n);
	byte_arrays		   = malloc(array_count * n * sizeof(unsigned char));	 // Allocate memory
	if (byte_arrays == NULL) {
		printf("Error: Memory allocation failed\n");
		return 1;
	}
	convert_into_nbyte_arrays(&short_val, TYPE_SHORT, byte_arrays, n);
	printf("Converted short value 0x%04X into %d-byte arrays:\n", short_val, n);
	print_byte_arrays(byte_arrays, array_count, n);
	free(byte_arrays);	  // Free allocated memory

	// Convert a long (4-byte) value into 4-byte arrays
	uint32_t long_val = 0xABCDEF12;
	n				  = 4;	  // Array size in bytes
	array_count		  = calculate_array_count(TYPE_LONG, n);
	byte_arrays		  = malloc(array_count * n * sizeof(unsigned char));	// Allocate memory
	if (byte_arrays == NULL) {
		printf("Error: Memory allocation failed\n");
		return 1;
	}
	convert_into_nbyte_arrays(&long_val, TYPE_LONG, byte_arrays, n);
	printf("Converted long value 0x%08X into %d-byte arrays:\n", long_val, n);
	print_byte_arrays(byte_arrays, array_count, n);
	free(byte_arrays);	  // Free allocated memory

	// Convert a long long (8-byte) value into 3-byte arrays
	uint64_t long_long_val = 0xFFFFFFFFFFFFFFFF;
	n					   = 3;	   // Array size in bytes
	array_count			   = calculate_array_count(TYPE_LONG_LONG, n);
	byte_arrays			   = malloc(array_count * n * sizeof(unsigned char));	 // Allocate memory
	if (byte_arrays == NULL) {
		printf("Error: Memory allocation failed\n");
		return 1;
	}
	convert_into_nbyte_arrays(&long_long_val, TYPE_LONG_LONG, byte_arrays, n);
	printf("Converted long long value 0x%016lX into %d-byte arrays:\n", long_long_val, n);
	print_byte_arrays(byte_arrays, array_count, n);
	free(byte_arrays);	  // Free allocated memory

	return 0;
}