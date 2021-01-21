# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 02:56:08 by hyungjki          #+#    #+#              #
#    Updated: 2021/01/22 03:36:36 by hyungjki         ###   ########.fr        #
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

LIBFTDIR = ./libft/

INCDIR = includes

LIBFT = libft.a

LIBPOS = $(addprefix $(LIBFTDIR), $(LIBFT))

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBPOS) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	cd $(LIBFTDIR) && make
	
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)
	
clean:
	rm -rf $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -rf $(NAME)
	cd $(LIBFTDIR) && rm -rf $(LIBFT)
	
re: fclean all

.PHONY: all clean fclean re