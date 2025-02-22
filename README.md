# 24 bit Integer Conversion Project

## Description
This project provides encoding functions that convert integers of various types (`char`, `short`, `long`, `long long`) into 3-byte arrays. It is also extended to support conversions into n-byte arrays where the size of the arrays (`n`) is provided as an input to a dedicated function.

## Supported Integer Types
- `char` (1-byte)
- `short` (2-byte)
- `long` (4-byte)
- `long long` (8-byte)

The project only supports unsigned integer types and needs to be extended further to handle signed ones.

## Project Structure

The project is organized as follows:
```
Project-root/
    ├── src/                                          # Source code for the linked list implementation
    │   └── integer_conversion.c
    ├── inc/                                          # Header files
    │   └── integer_conversion.h
    ├── test/                                         # Test files
    │   ├── test_integer_conversion.c
    │   └── test_integer_conversion_universal.c
    ├── CMakeLists.txt                                # CMake build configuration
    └── ReadMe                                        # This file
```

## Building the Project

1. Ensure you have CMake installed.
2. Navigate to the project root directory:
   ```bash
   cd Project-root
   ```
3. Create a build directory and configure the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```
4. Build the project
   ```bash
   make
   ```
5. Run the test executables
   ```bash
   ./test_integer_conversion
   ./test_integer_conversion_universal
   ```