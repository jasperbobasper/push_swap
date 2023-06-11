SRC =			main.c check.c push_swap.c stack_init.c stack_util.c s_p_utils.c r_utils.c utils.c sort_small_stack.c \
				lis.c sort_big_stack.c big_utils.c big_moves.c mem.c big_moves_2.c rr_multiples.c
OBJ =			$(SRC:.c=.o)
INC = libft/libft.a
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
CC = clang

all: $(NAME)

$(NAME): $(OBJ) libft
	$(CC) $(OBJ) $(FLAGS) -o $(NAME) $(INC)

libft:
	cd libft && $(MAKE)

%.o: %.c
	$(CC) -c $< -o $@

clean: cleanlibft
	rm -f $(OBJ)

cleanlibft:
	cd libft && $(MAKE) clean

fclean: clean fcleanlibft
	rm -f $(NAME)

fcleanlibft:
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re libft cleanlibft fcleanlibft