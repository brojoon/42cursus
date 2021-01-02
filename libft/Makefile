# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 02:56:07 by hyungjki          #+#    #+#              #
#    Updated: 2021/01/02 15:32:37 by hyungjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
          ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
          ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
          ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
          ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
          ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
          ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\

BSRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
        ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
        ft_lstclear.c ft_lstiter.c ft_lstmap.c \
				
OBJS		= $(SRCS:%.c=%.o)

BOBJS	= $(BSRCS:%.c=%.o)

CC = gcc
CLAGS		= -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

$(NAME):
	$(CC) $(CLAGS) -c $(SRCS) -I ./
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME)
	$(CC) $(CLAGS) -c $(BSRCS) -I ./
	$(AR) $(NAME) $(BOBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

reclean: fcelan all clean

.PHONY: all bonus clean fclean re reclean