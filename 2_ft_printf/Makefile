# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 02:56:08 by hyungjki          #+#    #+#              #
#    Updated: 2021/01/21 06:24:46 by hyungjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
SRC = ft_printf.c print_utils.c print_control.c print_hex.c \
		print_num.c print_pointer.c print_string.c 

SRCDIR = ./srcs/

LIBFTDIR = ./libft

INCDIR = includes

LIBFT = libft.a

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(INCDIR)
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re