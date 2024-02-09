NAME = push_swap
SRCS = push_swap.c list.c error.c instruction.c algorithm_utils.c algorithm_under6.c algorithm_over7.c coordinate_compression.c split.c
OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFALGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
