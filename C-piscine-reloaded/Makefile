# Common utility functions (shared by all exercises)
COMMON_SRC = ex99/ft_putchar.c
COMMON_OBJ = $(COMMON_SRC:.c=.o)

# Exercise source and objects
EX_SRC = ex06/ft_print_alphabet.c ex07/ft_print_numbers.c ex08/ft_is_negative.c
EX_OBJ = $(EX_SRC:.c=.o)

# Library combines common functions and exercise functions
LIBFT = libft.a
LIBFT_OBJ = $(COMMON_OBJ) $(EX_OBJ)

# Test configuration
TEST_DIR = test
UNITY_DIR = $(TEST_DIR)/unity
TEST_SRC = $(wildcard $(TEST_DIR)/test_*.c)
TEST_BIN_DIR = test_bin
TEST_BIN = $(patsubst $(TEST_DIR)/%.c, $(TEST_BIN_DIR)/%, $(TEST_SRC))

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(UNITY_DIR)

# Default target
all: $(LIBFT)

# Build static library
$(LIBFT): $(LIBFT_OBJ)
	@ar rcs $@ $^
	@echo "Built static library $@"

# Compile .c to .o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Run all tests
test: $(LIBFT) $(TEST_BIN)
	@echo "\nRunning tests..."
	@for t in $(TEST_BIN); do \
		echo "\nRunning $$t:"; \
		./$$t || exit 1; \
	done
	@echo "\nAll tests passed."

# Build test binaries (link with library and Unity)
$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c $(LIBFT) $(UNITY_DIR)/unity.c
	@mkdir -p $(TEST_BIN_DIR)
	$(CC) $(CFLAGS) $< $(UNITY_DIR)/unity.c $(LIBFT) -o $@
	@echo "Built test: $@"

# Clean object files
clean:
	rm -f $(COMMON_OBJ) $(EX_OBJ)
	@echo "Cleaned object files"

# Clean everything
fclean: clean
	rm -f $(LIBFT)
	rm -rf $(TEST_BIN_DIR)
	@echo "Full clean completed"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re test