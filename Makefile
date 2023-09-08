NAME = server.out

SRC = main.c \
		helpers.c \
		request.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBFT = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(OBJ)  $(LIBFT)/libft.a -o $(NAME)

$(OBJ): %.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

run: re
	./$(NAME)