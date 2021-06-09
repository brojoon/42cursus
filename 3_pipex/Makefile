NAME = pipex
CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =	pipex.c pipex_utils.c

LIBFTDIR = ./libft/

LIBFT = libft.a

LIBPOS = $(addprefix $(LIBFTDIR), $(LIBFT))

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBPOS) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -fsanitize=address

$(LIBPOS):
	$(MAKE) -C libft/ libft.a
	cp $(LIBPOS) $(LIBFT)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

all: $(NAME)
	
clean:
	rm -rf $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -rf $(NAME)
	cd $(LIBFTDIR) && rm -rf $(LIBFT)
	rm -rf $(LIBFT)

re: fclean all

.PHONY: all clean fclean re