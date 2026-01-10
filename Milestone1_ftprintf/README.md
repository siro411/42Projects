# ft_printf

*This project has been created as part of the 42 curriculum by anying.*

## Description

**ft_printf** is a custom implementation of the standard C library function `printf()`. The goal of this project is to recreate the behavior of `printf()` from scratch, handling formatted output with various conversion specifiers and format flags.

This project demonstrates understanding of:
- Variadic functions in C (`va_list`, `va_start`, `va_arg`, `va_end`)
- String parsing and formatting
- Type conversions and base conversions (decimal, hexadecimal)
- Memory management and buffer handling

The implementation supports the following conversions:
- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` / `%i` - Print a decimal (base 10) number
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in lowercase hexadecimal
- `%X` - Print a number in uppercase hexadecimal
- `%%` - Print a percent sign

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This will create the `libftprintf.a` static library.

### Available Make Commands

- `make` or `make all` - Compile the library
- `make clean` - Remove object files
- `make fclean` - Remove object files and the library
- `make re` - Recompile everything from scratch

### Usage

1. Include the header in your C file:
```c
#include "ft_printf.h"
```

2. Compile your program with the library:
```bash
cc your_program.c libftprintf.a -o your_program
```

3. Use `ft_printf()` just like the standard `printf()`:
```c
ft_printf("Hello, %s! You are %d years old.\n", "World", 42);
```

### Testing

A basic test program can be created:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello World");
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Decimal: %d\n", -42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    ft_printf("Percent: %%\n");
    return (0);
}
```

Compile and run:
```bash
cc main.c libftprintf.a -o test
./test
```

## Algorithm and Data Structure

### Core Architecture

The implementation follows a **parser-processor pattern** with a modular design:

```
Input → Parse format string → Identify conversion → Process & output → Return count
```

### Key Design Decisions

#### 1. **Direct Output Approach (No Buffer)**

**Choice:** Use `write()` directly for each character instead of buffering.

**Justification:**
- Project requirement explicitly states: "Do not implement the original printf()'s buffer management"
- Simpler implementation with fewer edge cases
- Easier to track printed character count
- Trade-off: Performance for correctness and simplicity

**Alternative considered:** Internal buffer with batch `write()` calls (rejected due to project constraints)

#### 2. **Recursive Number Conversion**

**Choice:** Use recursion to extract digits for numeric conversions.

**Implementation:**
```c
// For decimal numbers
if (n >= 10)
    count += ft_print_nbr(n / 10);  // Recursive call
count += ft_print_char((n % 10) + '0');
```

**Justification:**
- Clean and readable code
- Natural representation of "print high-order digits first" logic
- Stack depth limited by number of digits (max 10-11 for `int`)
- No need for temporary buffers or reverse operations

**Alternative considered:** Iterative approach with array (more complex, no significant benefit)

#### 3. **Conversion-Specific Functions**

**Choice:** Separate function for each conversion type (`ft_print_nbr`, `ft_print_hex`, `ft_print_str`, etc.)

**Justification:**
- **Single Responsibility Principle**: Each function handles one type
- Easy to test individual conversions
- Simple to extend with new conversions
- Clear separation of concerns

**Structure:**
```
ft_printf (main dispatcher)
    ├── ft_print_char   (handles %c)
    ├── ft_print_str    (handles %s)
    ├── ft_print_nbr    (handles %d, %i)
    ├── ft_print_unsigned (handles %u)
    ├── ft_print_hex    (handles %x, %X)
    └── ft_print_ptr    (handles %p)
```

#### 4. **Character Count Accumulation**

**Choice:** Return the printed character count from each function and accumulate in the main loop.

**Justification:**
- `printf()` standard behavior: return total characters printed
- Enables verification and testing
- Natural fit for recursive functions (count += recursive_call)
- Simple error detection (if `write()` fails, count can be adjusted)

#### 5. **Pointer Handling**

**Choice:** Cast pointer to `unsigned long` for hexadecimal conversion.

**Justification:**
- Pointers are memory addresses (unsigned values)
- `unsigned long` is guaranteed to hold pointer values on most platforms
- Enables reuse of hexadecimal conversion logic
- Standard approach: print "0x" prefix + hex representation

**Edge case:** NULL pointers print as "(nil)" for consistency with standard behavior

#### 6. **Base Conversion Algorithm**

**Choice:** Modulo-division method for hexadecimal conversion.

**Algorithm:**
```c
hex_digit = number % 16;        // Get rightmost digit
number = number / 16;           // Remove rightmost digit
map hex_digit to '0'-'9' or 'a'-'f'  // Character mapping
```

**Justification:**
- Standard algorithm for base conversion
- Works for any base (binary, octal, hexadecimal)
- Minimal memory footprint
- Efficient with recursion (prints left-to-right naturally)

### Data Structures

**Primary structure:** None required for mandatory part (no buffering)

**Implicit data flow:**
```
va_list → Format parser → Type-specific handler → write() → Count accumulator
```

**Memory management:**
- Stack-only allocation (recursion frames)
- No dynamic memory allocation (no `malloc`/`free`)
- No string buffers (direct character output)

### Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Print character (`%c`) | O(1) | O(1) |
| Print string (`%s`) | O(n) | O(1) |
| Print integer (`%d`) | O(log₁₀ n) | O(log₁₀ n) stack |
| Print hex (`%x`) | O(log₁₆ n) | O(log₁₆ n) stack |
| Overall ft_printf | O(m + Σconversions) | O(d) stack depth |

Where:
- n = numeric value
- m = format string length
- d = max recursion depth (≤ 20 for 64-bit integers)

## Resources

### Documentation & References

- [GNU C Library - Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
- [C Standard Library - printf() specification](https://en.cppreference.com/w/c/io/fprintf)
- [Variadic Functions in C](https://en.cppreference.com/w/c/variadic)
- [ASCII Table](https://www.asciitable.com/) - For character conversions
- Linux man pages: `man 3 printf`, `man 3 stdarg`

### Tutorials & Articles

- [Understanding printf() internals](https://www.cypress.com/file/54761/download)
- [Base conversion algorithms](https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/)
- [Variadic functions tutorial](https://www.cprogramming.com/tutorial/c/lesson17.html)

## Project Structure

```
ft_printf/
├── Makefile
├── ft_printf.h          # Header file with function prototypes
├── ft_printf.c          # Main function and dispatcher
├── ft_print_char.c      # Character and string conversions
├── ft_print_nbr.c       # Integer conversions (d, i, u)
├── ft_print_hex.c       # Hexadecimal conversion (x, X)
└── ft_print_ptr.c       # Pointer conversion (p)
```