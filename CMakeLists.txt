cmake_minimum_required(VERSION 3.10)
project(24BitIntegersChallenge C)

# Set C standard to POSIX
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include directories
include_directories(inc)

# Source files
set(SOURCES src/integer_conversion.c)

# Test executable for the coversion into 3-byte arrays
add_executable(test_integer_conversion test/test_integer_conversion.c ${SOURCES})

# Enable testing
enable_testing()

# Add tests for the coversion into 3-byte arrays
add_test(NAME test_integer_conversion COMMAND test_integer_conversion)
