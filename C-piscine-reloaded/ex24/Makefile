SRC_DIR = ./srcs

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

LIBFT = libft.a
LIBFT_OBJ = $(OBJ)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(LIBFT)

$(LIBFT):	$(OBJ)
			ar crs $(LIBFT) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm -f  $(OBJ)

fclean:
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re 
