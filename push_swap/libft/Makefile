SOURCES = 		ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_substr.c \
				ft_isascii.c ft_isprint.c ft_memcpy.c ft_memccpy.c \
				ft_memmove.c ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c \
				ft_memcmp.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_strmapi.c\
				ft_atoi.c ft_strlcpy.c ft_calloc.c ft_itoa.c ft_split.c \
				ft_strjoin.c ft_strdup.c ft_strlcat.c ft_strncmp.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_strnstr.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c 
SOURCES_B = 	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c

NAME = libft.a
OBJ_FILES = $(SOURCES:.c=.o)
OBJ_FILES_B = $(SOURCES_B:.c=.o)
INCLUDES = ./
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES)
	gcc $(FLAGS) -I$(INCLUDES) -c $(SOURCES)
	ar rcs $(NAME) $(OBJ_FILES)

bonus: $(NAME)
	gcc $(FLAGS) -I$(INCLUDES) -c $(SOURCES_B)
	ar rcs $(NAME) $(OBJ_FILES_B)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

cleanb: clean
	rm -f $(OBJ_FILES_B)

fcleanb: cleanb
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean cleanb fcleanb re