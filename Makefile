# Makefile

NAME = tic-tac-toe

SRCS = main.c \
	functions.c


all: $(NAME)

$(NAME): $(SRCS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all