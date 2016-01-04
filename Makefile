NAME = fdf

CC = gcc -Wall -Werror -Wextra -L/usr/X11/lib -lmlx -lXext -lX11

SRC =	./src/ft_matrix.c\
		./src/ft_matrix2.c\
		./src/ft_update_map.c\
		./src/ft_touch.c\
		./src/main.c\
		./src/mlx.c\
		./src/fdf.c\
		./src/map_error.c

COMPILE = echo "\033[36mCompile --fdf-- ...."
COMPILED = echo "\033[32mCompiled --fdf-- Successfully"
CLEAN = echo "\033[36mClean --fdf-- ...."
CLEANED = echo "\033[32mCleaned --fdf-- Successfully"

all: $(NAME)

$(NAME):
	@$(COMPILE)
	@make -C ./libft re
	@$(CC) -o $(NAME) $(SRC) ./libft/libft.a 
	@$(COMPILED)

norme:
	@norminette $(SRC) ./src/fdf.h
	@make -C ./libft norme

clean:
	@$(CLEAN)
	@make -C ./libft clean
	@$(CLEANED)

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re : fclean all