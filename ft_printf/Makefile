NAME = libftprintf.a

SRC = 	ft_putchar_fd.c ft_putnbr_fd.c ft_printf.c aux_functions_printf.c\
		2_aux_functions_printf.c

HEADER = ft_printf.h
OBJ = $(SRC:.c=.o) 

FLGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)
	
%.o:%.c Makefile
	cc $(FLGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re