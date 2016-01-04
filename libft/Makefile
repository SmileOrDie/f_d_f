NAME = libft.a

CC = gcc -Wall -Werror -Wextra

SRC =	ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memalloc.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memdel.c\
		ft_memset.c\
		ft_memmove.c\
		ft_memcmp.c\
		ft_memchr.c\
		ft_putchar.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_strcat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strstr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strsub.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strsub.c\
		ft_itoa.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_strtrim.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_strsplit.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_len_num.c\
		get_next_line.c\
		tabc_to_tabi.c

SRC_OBJ =	ft_atoi.o\
			ft_bzero.o\
			ft_isalnum.o\
			ft_isalpha.o\
			ft_isascii.o\
			ft_isdigit.o\
			ft_isprint.o\
			ft_memalloc.o\
			ft_memcpy.o\
			ft_memccpy.o\
			ft_memdel.o\
			ft_memset.o\
			ft_memmove.o\
			ft_memcmp.o\
			ft_memchr.o\
			ft_putchar.o\
			ft_putendl.o\
			ft_putnbr.o\
			ft_putstr.o\
			ft_strcat.o\
			ft_strlcat.o\
			ft_strchr.o\
			ft_strrchr.o\
			ft_strclr.o\
			ft_strcmp.o\
			ft_strcpy.o\
			ft_strdel.o\
			ft_strdup.o\
			ft_strequ.o\
			ft_striter.o\
			ft_striteri.o\
			ft_strjoin.o\
			ft_strlen.o\
			ft_strmap.o\
			ft_strmapi.o\
			ft_strncat.o\
			ft_strncmp.o\
			ft_strncat.o\
			ft_strncmp.o\
			ft_strncpy.o\
			ft_strnequ.o\
			ft_strnew.o\
			ft_strstr.o\
			ft_strnstr.o\
			ft_strsub.o\
			ft_tolower.o\
			ft_toupper.o\
			ft_strsub.o\
			ft_itoa.o\
			ft_putchar_fd.o\
			ft_putnbr_fd.o\
			ft_putstr_fd.o\
			ft_putendl_fd.o\
			ft_strtrim.o\
			ft_lstnew.o\
			ft_lstdelone.o\
			ft_lstdel.o\
			ft_lstadd.o\
			ft_strsplit.o\
			ft_lstiter.o\
			ft_lstmap.o\
			ft_len_num.o\
			get_next_line.o\
			tabc_to_tabi.o

COMPILE = echo "\033[36mCompile --Libft-- ...."
COMPILED = echo "\033[32mCompiled --Libft-- Successfully"
CLEAN = echo "\033[36mClean --Libft-- ...."
CLEANED = echo "\033[32mCleaned --Libft-- Successfully"

all: $(NAME)

$(NAME):
	@$(COMPILE)
	@$(CC) -c $(SRC)
	@ar rc $(NAME) $(SRC_OBJ)
	@ranlib $(NAME)
	@$(COMPILED)

norme:
	@norminette $(SRC) ./libft.h

clean:
	@$(CLEAN)
	@rm -f $(SRC_OBJ)
	@$(CLEANED)

fclean: clean
	@rm -f $(NAME)

re : fclean all