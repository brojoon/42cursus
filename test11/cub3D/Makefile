MLX				=	-lmlx -lm -framework OpenGL -framework AppKit

NAME			=	cub3D

SRCS			=	src/cub3d.c \
					src/bitmap.c \
					src/camera.c \
					src/draw_sprite.c \
					src/error.c \
					src/event.c \
					src/gnl.c \
					src/health.c \
					src/hungry.c \
					src/image.c \
					src/init1.c \
					src/init2.c \
					src/key.c \
					src/loop.c \
					src/player.c \
					src/raycast1.c \
					src/raycast2.c \
					src/reader_color.c \
					src/reader_path.c \
					src/reader_win.c \
					src/reader.c \
					src/special.c \
					src/sprite.c \
					src/texture.c \
					src/tool.c \
					src/translate.c \
					src/util1.c \
					src/util2.c \
					src/util3.c \
					src/util4.c

OBJSRCS			=	$(SRCS:.c=.o)

$(NAME)	: $(OBJSRCS)
	@echo "\033[33m[Remove last version...]"
	@rm -rf cub3D
	@echo "\033[33m[cub3D compilation...]"
	@gcc $(OBJSRCS) -I./includes -I./usr/include -Wall -Wextra -Werror $(MLX) -o $(NAME)
	@echo "[Remove .o files...]"
	@rm -rf $(OBJSRCS)
	@echo "\033[33m[DONE!]"

all : $(NAME)

clean :
	rm -rf $(OBJSRCS)

fclean : clean
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all

bonus : $(NAME)
