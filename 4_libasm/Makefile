# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 03:40:47 by hyungjki          #+#    #+#              #
#    Updated: 2021/03/17 12:55:04 by hyungjki         ###   ########.fr        #
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
ifdef WITH_BONUS
		OBJS_FILES = $(BONUS_OBJS)
else
		OBJS_FILES = $(OBJS)
endif

$(NAME): $(OBJS_FILES)
ifdef WITH_BONUS
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)
else
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
endif

%.o: %.s
	$(NA) $(NA_FLAGS) $< -o $@

all: $(NAME)

bonus:
		make WITH_BONUS=1 all
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