NAME = push_swap

SRC = push_swap.c ft_atoi.c quicksort.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = 

all:	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

run: all
	./$(NAME) $(ARGS)
