NAME = push_swap

SRC = push_swap.c quicksort.c radixsort.c mysort.c \
stack_operations.c stack_utils.c stack_utils_2.c convert_number.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Werror -Wextra

FLAGS = 

all:	$(NAME) 

$(NAME):	$(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(OBJ) -o $(NAME) -L./libft -lft -I./libft/include

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ)

fclean:	clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re:	fclean all

run: all
	./$(NAME) $(ARGS)

