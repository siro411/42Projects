SRCS = ft_printf.c \
       ft_print_char.c \
       ft_print_str.c \
       ft_print_nbr.c \
       ft_print_unsigned.c \
       ft_print_hex.c \
       ft_print_ptr.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc 
CFLAGS = -Wall -Werror -Wextra
RM = rm -f 
AR = ar crs

all:			$(NAME)

$(NAME):	$(OBJS)
					$(AR) $(NAME) $(OBJS)

%.o: %.c 
		 			$(CC) $(CFLAGS) -c -o $@ $< -I .

clean: 
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME) 

re:				fclean all

.PHONY:		all clean fclean re 