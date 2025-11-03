Of course. Managing multiple libraries in a `Makefile` is a fundamental skill. Here is a general guide on the concepts and structure for doing this, without giving you a direct solution for `push_swap`.

### The Core Idea: Dependencies

A `Makefile` is all about dependencies. Your final executable (`push_swap`) depends on your project's object files (`.o` files). Those object files depend on your source files (`.c` files).

When you add libraries, you're just adding another layer of dependencies. Your final executable now *also* depends on the compiled library files (e.g., `libft.a`). The library file, in turn, depends on its own source files.

The process looks like this:

1.  **Compile Library 1** -> `library1.a`
2.  **Compile Library 2** -> `library2.a`
3.  **Compile Your Main Project's `.c` files** -> `main.o`, `utils.o`, etc.
4.  **Link everything together** -> `my_program`

### How to Manage This in a Makefile

Here’s a step-by-step tutorial on how to structure your `Makefile` to handle this.

#### 1. Use Variables to Stay Organized

Good `Makefiles` are easy to read and modify. Start by defining variables for your compiler, flags, source files, and library paths.

```makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Your main executable name
NAME = my_program

# Your project's source and object files
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

# --- Library Setup ---
# Path to the library directories
LIBFT_DIR = ./libft
PRINTF_DIR = ./my_printf

# The final library archive files we need
LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/printf.a
```

#### 2. Delegate Library Compilation with Sub-Makes

Your main `Makefile` shouldn't know *how* to build `libft`. It only needs to know that it *needs* `libft.a`. You can tell `make` to go into a library's directory and use its own `Makefile` to build it.

This is the key to managing multiple libraries cleanly.

```makefile
# This is the main target that builds everything
all: $(NAME)

# Rule to build the final executable
$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A) $(PRINTF_A)

# --- Rules to build the libraries ---

# To get libft.a, run 'make' in its directory
$(LIBFT_A):
	@make -C $(LIBFT_DIR)

# To get printf.a, run 'make' in its directory
$(PRINTF_A):
	@make -C $(PRINTF_DIR)
```

**How this works:**

*   When you run `make`, it tries to build `$(NAME)`.
*   It sees that `$(NAME)` depends on `$(LIBFT_A)`.
*   It then looks for a rule to build `$(LIBFT_A)`. It finds our rule and runs `make -C ./libft`.
*   The `libft` `Makefile` does its job and produces `libft.a`.
*   The main `Makefile` then continues, sees the file now exists, and moves on to the next dependency.
*   Finally, the linking command `$(CC) ... $(OBJS) $(LIBFT_A) $(PRINTF_A)` bundles everything into your final executable.

*Note on Linking:* The command above links the `.a` files directly by path. This is simple and explicit. An alternative method is using the `-L` and `-l` flags (`-L$(LIBFT_DIR) -lft`), which tells the linker where to look for libraries and which ones to use by name. For local static libraries, providing the direct path is often clearer.

#### 3. Generic Rule for Object Files

You still need the standard rule to compile your project's `.c` files into `.o` files.

```makefile
# Generic rule to turn any .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

#### 4. Extending `clean` and `fclean`

Your `clean` and `fclean` rules should also clean up the libraries. You can delegate this in the same way.

```makefile
clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all
```

### Summary: The Complete Structure

Putting it all together, a generic `Makefile` template looks like this:

```makefile
# ------------------- #
#     VARIABLES       #
# ------------------- #
NAME = my_program
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Project sources
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

# Library paths and files
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./my_printf
PRINTF_A = $(PRINTF_DIR)/printf.a

# ------------------- #
#        RULES        #
# ------------------- #
.PHONY: all clean fclean re

all: $(NAME)

# --- Main Executable ---
$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A)
	# Link the object files and the library archives
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A) $(PRINTF_A)

# --- Libraries ---
$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(PRINTF_A):
	@make -C $(PRINTF_DIR)

# --- Object Files ---
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# --- Cleaning ---
clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all
```

By using this structure, you can add as many libraries as you want. Just add new variables for the library path and archive file, add the archive to the `$(NAME)` dependency list, create a rule to build it using `make -C`, and update your `clean`/`fclean` rules.