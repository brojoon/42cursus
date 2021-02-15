# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 01:54:39 by hyungjki          #+#    #+#              #
#    Updated: 2021/02/11 23:40:02 by hyungjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC = gcc
CFLAGS = -wall -Wextra -Werror -lm -lbsd -lX11 -lXext -g

INC_DIR = ./includes
MLX_DIR = ./minilibx-linux
SRC_DIR = ./sources
LIB_DIR = ./libft

LIBFT = libft.a
MLX = libmlx_Linux.a

SRC =	main.c ft_parsing.c ft_parsing_2.c \
		ft_read_map.c ft_window.c ft_orientation.c \
		ft_deplacements.c ft_textures.c ft_bmp.c \
		ft_sprite.c ft_utils.c ft_check_error.c \
		ft_utils_2.c ft_utils_3.c ft_utils_4.c ft_prite_2.c

SRCS = $(addprefix$(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c -I$(INC_DIR) -I$(MLX_DIR) -I$(LIB_DIR) $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	cd $(MLX_DIR) && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_DIR)$(LIBFT) $(MLX_DIR)$(MLX)

all: $(NAME)

clean:
	cd $(LIB_DIR) && make clean
	cd $(MLX_DIR) && make clean
	rm -rf $(SRC_DIR)/*.o

fclean: clean
	cd $(LIB_DIR) && make fclean
	cd $(MLX_DIR) && make fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

