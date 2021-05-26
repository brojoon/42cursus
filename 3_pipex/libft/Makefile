# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 02:56:08 by hyungjki          #+#    #+#              #
#    Updated: 2021/01/21 08:12:06 by hyungjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
SRCS =  ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
		ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif
all: $(NAME)
$(NAME): $(OBJ_FILES)
ifdef WITH_BONUS
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)
else
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
endif
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $<
bonus:
	make WITH_BONUS=1 all
$(OBJS_BONUS): %.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all bonus clean fclean re