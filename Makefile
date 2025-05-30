# -------------------------Utils----------------------------------------------

NAME			=	so_long

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror -g

LIBFT_NAME		=	libft.a

MLX_NAME		=	libmlx.a

LIBFT			=	libft/ft_bzero.c\
					libft/ft_isalnum.c\
					libft/ft_isalpha.c\
					libft/ft_isascii.c\
					libft/ft_isdigit.c\
					libft/ft_isprint.c\
					libft/ft_memcpy.c\
					libft/ft_memset.c\
					libft/ft_strlcpy.c\
					libft/ft_strlcat.c\
					libft/ft_strlen.c\
					libft/ft_memmove.c\
					libft/ft_toupper.c\
					libft/ft_tolower.c\
					libft/ft_strchr.c\
					libft/ft_strrchr.c\
					libft/ft_strncmp.c\
					libft/ft_memchr.c\
					libft/ft_memcmp.c\
					libft/ft_strnstr.c\
					libft/ft_atoi.c\
					libft/ft_strdup.c\
					libft/ft_calloc.c\
					libft/ft_substr.c\
					libft/ft_strjoin.c\
					libft/ft_split.c\
					libft/ft_itoa.c\
					libft/ft_strtrim.c\
					libft/ft_putchar_fd.c\
					libft/ft_putstr_fd.c\
					libft/ft_putendl_fd.c\
					libft/ft_putnbr_fd.c\
					libft/ft_strmapi.c\
					libft/ft_striteri.c\
					libft/ft_printf/ft_printf.c\
					libft/ft_printf/printf_putnbr_base.c\
					libft/ft_printf/printf_putstr.c\
					libft/ft_printf/printf_putnbr_x.c\
					libft/gnl/get_next_line.c

LIBX			=	minilibx
SRC				=	main.c\
					parse.c\
					utils.c\
					listen.c\
					put_texture.c\
					error.c\
					check_map.c

OBJ_LIBFT		=	$(LIBFT:.c=.o)
OBJ				=	$(SRC:.c=.o)

# -------------------------------Echo Cmd--------------------------------------

BLUE				=	\e[3;34m
FLASH				=	\e[5m
RESET				=	\e[0m
DELETE				=	\e[A
BACKGROUND_BLACK	=	\e[36;40m

# ------------------------------Make Cmd------------------------------------------------------------

%.o: %.c
	@sleep 0.03s
	@echo "$(BACKGROUND_BLACK)$(BLUE)Compil $<...$(DELETE)"
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "      Compil Libft Success                                            $(DELETE)"

$(NAME): $(OBJ_LIBFT)
	@git clone -q git@github.com:42paris/minilibx-linux.git minilibx
	@echo "$(BACKGROUND_BLACK)$(BLUE)     Minilibx clone success!$(RESET)"
	@ar rcs $(LIBFT_NAME) $(OBJ_LIBFT)
	@echo "\n"
	@echo "\n\e[41m$(BLUE)! Start Error Minilibx !$(RESET)"
	@make -sC $(LIBX)
	@echo "\e[41m$(BLUE)! End Error Minilibx !$(RESET)$(BLUE)$(BACKGROUND_BLACK)\n"
	@echo "$(BLUE)"
	@echo "    ╔══════════════════════╗"
	@echo "    ║    $(FLASH)Libft & Mlx OK $(RESET)$(BACKGROUND_BLACK)$(BLUE)   ║"
	@echo "    ╚══════════════════════╝\n$(RESET)"

all: $(NAME)
	@$(CC) $(FLAGS) $(SRC) $(LIBFT_NAME) -L$(LIBX) -lmlx -lXext -lX11 -lbsd -lm -o $(NAME)


test parse:
	@cc parse.c libft/gnl/*.c libft/*.c libft/ft_printf/*.c
	@echo $(BACKGROUND_BLACK)"Ok"$(RESET)

clean:
	@rm -f $(OBJ_LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_NAME)
	@rm -rf $(LIBX)

re: fclean all

.PHONY: all clean fclean re
