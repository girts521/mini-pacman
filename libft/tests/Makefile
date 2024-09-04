NAME = test

SRCS = ft_lstnew_test.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L../ -lft

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re	