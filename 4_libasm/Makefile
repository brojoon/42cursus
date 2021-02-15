# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 03:40:47 by hyungjki          #+#    #+#              #
#    Updated: 2021/02/08 03:49:21 by hyungjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
NA = nasm
NA_FLAGS = -f macho64
FLAGS = -Wall -Werror -Wextra
AR = ar
AFLAGS = rcs
SRCS =	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_strdup.s
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(NA) $(NA_FLAGS) -c $<

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re