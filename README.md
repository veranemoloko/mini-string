# mini-string
My implementation of core string functions with basic error handling and test coverage. Recreates essential string operations from the C standard library.

## String Functions:
- s21_strlen() - calculates string length with NULL safety
- s21_strcmp() - compares strings with NULL handling
- s21_strcpy() - safe string copying with buffer validation
- s21_strcat() - concatenates strings with input checking
- s21_strchr() - locates first character occurrence

## Memory Functions:
- s21_memcpy() - copies memory blocks with overlap protection
- s21_memset() - fills memory with constant byte
- s21_strstr() - finds substring with boundary checks

## Testing:
# The project includes test cases covering:
- Normal operation scenarios
- Edge cases (NULL pointers, empty strings)
- Buffer boundary conditions
- Character search functionality

