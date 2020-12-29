# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 02:56:07 by hyungjki          #+#    #+#              #
#    Updated: 2020/12/30 03:23:02 by hyungjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR 		= ar
ARFLAGS = rcs
SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
TARGET	= libft.a
RM		= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all: ${TARGET}

${TARGET}: ${OBJS}
	${AR} ${ARFLAGS} $@ $<

clean:
	${RM} {OBJS}

fclean: clean
	${RM} ${TARGET}

re: fclean all

.PHONY: all clean fclean re .c.o