/* integer_conversion,c */
#include <stdio.h>
#include <stdlib.h>

#include "../inc/integer_conversion.h"

void convert_char(uint8_t val, uint8_t output[3])
{
	// Store the 1-byte value in the first byte and fill the rest with 0
	output[0] = val;
	output[1] = 0;
	output[2] = 0;
}

void convert_short(uint16_t val, uint8_t output[3])
{
	output[0] = (val >> 8) & 0xFF;	  // Store the high byte
	output[1] = val & 0xFF;			  // Store the low byte
	output[2] = 0;					  // Fill the rest with 0
}

size_t convert_long(const void *val, IntValueType type, uint8_t (*output)[3])
{
	size_t	 array_count = 0;	 // Counts the number of 3-byte arrays needed to store the input value
	uint64_t temp_val	 = 0;	 // Use a 64-bit temporary variable to handle both 4-byte and 8-byte integers types

	switch (type) {
	case TYPE_LONG:
		temp_val = *(const uint32_t *)val;
		break;
	case TYPE_LONG_LONG:
		temp_val = *(const uint64_t *)val;
		break;
	default:
		printf("Error: Unsupported type\n");
		return 0;
	}

	while (temp_val > 0) {
		// Store the lowest 24 bits in the 3-byte array
		output[array_count][0] = (temp_val >> 16) & 0xFF;
		output[array_count][1] = (temp_val >> 8) & 0xFF;
		output[array_count][2] = temp_val & 0xFF;
		temp_val >>= 24;	// Shift right by 24 bits to process the next array
		array_count++;
	}

	return array_count;
}

// Universal conversion function
int convert_into_nbyte_arrays(const void *value, IntValueType type, uint8_t *output, int n)
{
	int		 chunk_count = 0;
	uint64_t temp_value	 = 0;	 // Use a 64-bit temporary variable to handle all types

	// Copy the value into the temporary variable based on the type
	switch (type) {
	case TYPE_CHAR:
		temp_value = *(const uint8_t *)value;
		break;
	case TYPE_SHORT:
		temp_value = *(const uint16_t *)value;
		break;
	case TYPE_LONG:
		temp_value = *(const uint32_t *)value;
		break;
	case TYPE_LONG_LONG:
		temp_value = *(const uint64_t *)value;
		break;
	default:
		printf("Error: Unsupported type\n");
		return 0;
	}

	// Convert the value into n-byte chunks
	while (temp_value > 0) {
		for (int i = 0; i < n; i++) {
			output[chunk_count * n + i] = (temp_value >> ((n - i - 1) * 8)) & 0xFF;
		}
		temp_value >>= (n * 8);	   // Shift right by n*8 bits to process the next chunk
		chunk_count++;
	}

	if (temp_value > 0) {
		printf("Warning: Value truncated, insufficient chunks allocated\n");
	}

	return chunk_count;
}
