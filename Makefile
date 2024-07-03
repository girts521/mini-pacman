NAME = so_long

LIBFT_DIR = libft
MLX_DIR = minilibx-linux

MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = get_next_line.c on_destroy.c draw_sprite.c redraw_sprite.c on_keypress.c redraw.c \
		 render_map.c load_map.c animate_sprite.c on_win.c on_lose.c move_ghosts.c validate_path.c main.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I/usr/include -Imlx -I./includes -I$(LIBFT_DIR) -I./

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_SRCS = ft_strlen.c ft_toupper.c ft_tolower.c ft_isalpha.c \
             ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
             ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
             ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
             ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
             ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
             ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putchar_fd.c \
             ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
			 ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			 ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstsize.c

LIBFT_OBJS = $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS:.c=.o))

all: $(MLX_LIB) $(LIBFT_OBJS) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_OBJS) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_OBJS): $(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft minilibx-linux
