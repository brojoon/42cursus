NAME = philo_bonus

CC = gcc

CFLAGS = -Wall -Wextra

SRCS = main.c philo_fork.c \
	   monitor_thread.c utils.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I.

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(NAME) -pthread -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
