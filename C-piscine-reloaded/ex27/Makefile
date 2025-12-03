SRC_DIR = ./srcs

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = ft_display_file


all: $(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f ${OBJ}

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
