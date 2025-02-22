/* test_integer_conversion.c */
#include <stdio.h>

#include "../inc/integer_conversion.h"

// Helper function to print the 3-byte arrays
void print_byte_arrays(const uint8_t (*arrays)[3], int array_count)
{
	for (int i = array_count - 1; i >= 0; i--) {
		printf("Array %d: %02X %02X %02X\n", i, arrays[i][0], arrays[i][1], arrays[i][2]);
	}
}

int main()
{
	uint8_t char_val = 0xAB;	// Example char (1-byte) value
	uint8_t char_byte_array[3];
	convert_char(char_val, char_byte_array);
	printf("Coverted char value 0x%02X into 3-byte array:\n%02X %02X %02X\n", char_val, char_byte_array[0], char_byte_array[1], char_byte_array[2]);

	uint16_t short_val = 0xABCD;	// Example short (2-byte) value
	uint8_t	 short_byte_array[3];
	convert_short(short_val, short_byte_array);
	printf("Coverted short value 0x%04X into 3-byte array:\n%02X %02X %02X\n", short_val, short_byte_array[0], short_byte_array[1], short_byte_array[2]);

	uint32_t long_val = 0xABCDEF12;	   // Example 32-bit (4-byte) integer
	uint8_t	 long_byte_array[2][3];
	size_t	 long_byte_array_count = convert_long(&long_val, TYPE_LONG, long_byte_array);
	printf("Coverted long value 0x%08X into 3-byte arrays:\n", long_val);
	print_byte_arrays(long_byte_array, long_byte_array_count);

	uint64_t long_long_val = 0xFFFFFFFFFFFFFFFF;	// Example 64-bit (8-byte) integer
	uint8_t	 long_long_byte_array[3][3];
	size_t	 long_long_byte_array_count = convert_long(&long_long_val, TYPE_LONG_LONG, long_long_byte_array);
	printf("Coverted long long value 0x%016lX into 3-byte arrays:\n", long_long_val);
	print_byte_arrays(long_long_byte_array, long_long_byte_array_count);

	return 0;
}
