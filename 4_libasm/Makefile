# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 03:40:47 by hyungjki          #+#    #+#              #
#    Updated: 2021/03/17 08:56:15 by hyungjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

CC = gcc
NA = nasm
NA_FLAGS = -f elf64
FLAGS = -Wall -Werror -Wextra -L. -lasm
AR = ar
AFLAGS = rcs

TEST = test_case
TEST_BONUS = test_case_bonus

SRCS =	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_strdup.s ft_read.s
BONUS_SRCS = ft_list_push_front_bonus.s ft_list_size_bonus.s

OBJS = $(SRCS:.s=.o)
BONUS_OBJS = $(BONUS_SRCS:.s=.o)


$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.s
	$(NA) $(NA_FLAGS) $< -o $@

all: $(NAME)

bonus:	$(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)

test: $(NAME)
	$(CC) $(FLAGS) -o $(TEST) main.c $(NAME)
	./$(TEST)

test_bonus: bonus
	$(CC) $(FLAGS) -o $(TEST_BONUS) main_bonus.c $(NAME)
	./$(TEST_BONUS)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) $(TEST) $(TEST_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus test