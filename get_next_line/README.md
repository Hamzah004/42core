*This project has been created as part of the 42 curriculum by hbani-at.*

## Description

**get_next_line** is a C function that reads and returns one line at a time from a file descriptor. This project is a fundamental exercise in file I/O manipulation and memory management in C. The main goal is to create a function that successfully reads lines from a file while managing a buffer efficiently and handling edge cases like files without newlines.

The function demonstrates key programming concepts:
- Efficient file reading with customizable buffer sizes
- Static variables for state management across multiple function calls
- Dynamic memory allocation and deallocation
- String manipulation and parsing

## Instructions

### Compilation

To compile the project into a static library:

```bash
make
```

This will create `libftgetnextline.a`.

To compile the bonus version (supporting multiple file descriptors simultaneously):

```bash
make bonus
```

### Cleaning

To remove object files:

```bash
make clean
```

To remove all generated files (objects and library):

```bash
make fclean
```

To rebuild everything from scratch:

```bash
make re
```

### Usage

Include the header file in your project:

```c
#include "get_next_line.h"
```

Then call the function:

```c
int fd = open("filename.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

### Compilation with Custom Buffer Size

You can define a custom `BUFFER_SIZE` at compile time:

```bash
gcc -D BUFFER_SIZE=42 -c get_next_line.c
```

The default `BUFFER_SIZE` is defined as 5 in the header file but can be any positive integer.

## Algorithm Explanation and Justification

### Algorithm Overview

The `get_next_line` function implements a **static buffer approach** to efficiently read lines from file descriptors:

1. **Initialization**: Allocate a temporary buffer of size `BUFFER_SIZE + 1`
2. **Read Phase**: Read chunks from the file descriptor into the temporary buffer
3. **Accumulation**: Use a static variable (`stash`) to accumulate read data until a newline is found
4. **Line Extraction**: Extract the complete line (including the newline character)
5. **Stash Management**: Update the stash to contain only unread data for the next call
6. **Memory Cleanup**: Free intermediate buffers appropriately

### Why This Approach?

**1. Memory Efficiency**
- The static `stash` variable persists across function calls, avoiding re-reading the same data
- Only one line is kept in memory at any time
- Buffer size is customizable at compile time, allowing flexibility for different use cases

**2. Scalability**
- Works efficiently with any buffer size, from small (5 bytes) to large (1024+ bytes)
- Smaller buffers = more read calls but less memory per call
- Larger buffers = fewer read calls but more memory usage

**3. Correctness**
- Handles files with and without trailing newlines
- Properly distinguishes between EOF and newline characters
- Manages empty files and single-line files correctly

### Complexity Analysis

- **Time Complexity**: O(n) where n is the file size. Each character is read once and processed once.
- **Space Complexity**: O(BUFFER_SIZE + L) where L is the maximum line length. The stash grows with incomplete lines but is freed after each line is returned.

### Key Implementation Details

**Static Buffer Strategy**: The `stash` static variable acts as a persistent buffer that survives between function calls. This is crucial for:
- Resuming from where the previous call left off
- Handling lines that span multiple `read()` calls
- Maintaining state across multiple `fd` operations (in bonus version)

**Memory Management**: Each call to `get_next_line()` allocates a temporary buffer for reading and carefully manages freeing:
- The temporary read buffer is freed after accumulation
- The extracted line is returned (caller must free)
- The remaining stash is preserved for the next call
- All allocations are freed on error conditions

**Line Detection**: The algorithm uses `ft_strchr()` to efficiently find newlines without scanning the entire accumulated buffer each time.

## Bonus Features

The bonus version (`get_next_line_bonus.c`) extends the functionality to:

- Support **multiple file descriptors simultaneously**
- Each file descriptor has its own independent stash
- Files can be read in any order and interspersed

This is achieved using an **array of stashes** instead of a single static variable, allowing each FD to maintain its own reading state.

## File Structure

```
.
├── get_next_line.c           # Main function implementation
├── get_next_line.h           # Header file with function declarations
├── get_next_line_utils.c     # Utility functions for the main version
├── get_next_line_bonus.c     # Bonus version with multiple FD support
├── get_next_line_bonus.h     # Bonus version header
├── get_next_line_utils_bonus.c # Bonus version utility functions
├── main.c                     # Example usage (optional testing)
├── Makefile                   # Build configuration
└── README.md                  # This file
```

## Resources

### Documentation & References

- **man 2 read**: Understanding the read() system call
- **man 2 open**: File descriptor creation
- **man 3 malloc/free**: Dynamic memory allocation
- **C Standard Library**: String manipulation functions reference

### Key System Calls Used

| Function | Purpose | Man Page |
|----------|---------|----------|
| `read()` | Read data from file descriptor | `man 2 read` |
| `malloc()` | Allocate dynamic memory | `man 3 malloc` |
| `free()` | Deallocate memory | `man 3 free` |
| `open()` | Open file descriptor | `man 2 open` |
| `close()` | Close file descriptor | `man 2 close` |

### Related Concepts

- Buffer management and I/O optimization
- Static variables in C and their persistence
- Memory management best practices
- File descriptor handling
- String processing and parsing

## AI Usage

AI tools were not used in the development of this project. This implementation was completed through manual coding following the 42 curriculum specifications and requirements.

## Testing

A simple test file can be generated using:

```bash
make test
```

This creates a `test` file with sample content. You can then test the function with your own implementation.

## Notes

- The function returns `NULL` when the end of file is reached or on error
- Each returned line must be freed by the caller
- The `BUFFER_SIZE` macro can significantly affect performance; test with different values for optimal results
- The bonus version requires careful FD management to avoid conflicts
