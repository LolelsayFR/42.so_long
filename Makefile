# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 23:30:22 by emaillet          #+#    #+#              #
#    Updated: 2025/01/17 23:59:44 by emaillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

STORY_MAP		=	maps/story/1.ber\
					maps/story/2.ber\
					maps/story/3.ber\
					maps/story/4.ber\
					maps/story/5.ber\
					maps/story/6.ber\
					maps/story/7.ber\
					maps/story/8.ber\
					maps/story/9.ber\
					maps/story/10.ber

SRC				=	script/main.c\
					script/player/player.c\
					script/player/player2.c\
					script/player/player_action.c\
					script/enemy/enemy.c\
					script/enemy/enemy2.c\
					script/render/render.c\
					script/render/tools.c\
					script/utils/img.c\
					script/map/init_map.c\
					script/map/init_map2.c\
					script/map/init_map3.c\
					script/map/init_room.c\
					script/map/tilepos.c\
					script/map/tilepos2.c\
					script/map/tilepos3.c\
					script/map/tilepos4.c\
					script/utils/free_global.c\
					script/init/init_global.c\
					script/init/init_sprite0.c\
					script/init/init_sprite1.c\
					script/init/init_sprite2.c\
					script/init/init_sprite3.c\
					script/init/init_sprite4.c\
					script/utils/hud.c\
					script/utils/menu.c\
					script/utils/minimap.c\
					script/utils/logs.c\
					script/map/floodfill.c

GNL_PATH		=	./modules/get_next_line
GNL				=	$(GNL_PATH)/get_next_line_bonus.c\
					$(GNL_PATH)/get_next_line_utils_bonus.c

LIBFT_PATH		=	./modules/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

FTPRINTF_PATH	=	./modules/ft_printf
FTPRINTF		=	$(FTPRINTF_PATH)/libftprintf.a

MINILIBX_PATH	=	./modules/minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

CFLAGS			=	-lXext -lX11 -Wall -Werror -Wextra -g -lm

all:	hello $(NAME) info

hello:
	@echo "\e[48;2;100;0;100;1m Welcome to SoLong Makefile\e[0m\n"

info: hello
	@echo "\n\e[48;2;70;70;70;1m SoLong usage : \e[0m\n"
	@echo "./so_long <map path> \n make story\n"

lib: hello $(LIBFT) $(FTPRINTF) $(MINILIBX)

$(NAME): ${LIBFT} ${FTPRINTF} ${MINILIBX} ${GNL} ${SRC}
	@echo "\e[48;2;0;155;0;1m Compile Solong \e[0m\n"
	cc ${SRC} ${MINILIBX} ${GNL} ${LIBFT} ${FTPRINTF} ${CFLAGS} -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

$(LIBFT):
	@echo "\e[48;2;0;155;0;1m Make LIBFT \e[0m\n"
	@$(MAKE) --no-print-directory bonus -C $(LIBFT_PATH)
	@$(MAKE) --no-print-directory  clean  -C $(LIBFT_PATH)
	@echo "\e[48;2;0;0;155;1m Done for LIBFT \e[0m\n"

$(FTPRINTF):
	@echo "\e[48;2;0;155;0;1m Make FT_PRINTF \e[0m\n"
	@$(MAKE) --no-print-directory -C $(FTPRINTF_PATH)
	@$(MAKE) --no-print-directory clean -C $(FTPRINTF_PATH)
	@echo "\e[48;2;0;0;155;1m Done for FT_PRINTF \e[0m\n"

$(MINILIBX):
	@echo "\e[48;2;0;155;0;1m Make MINILIBX \e[0m\n"
	@$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
	@echo "\n\e[48;2;0;0;155;1m Done for MINILIBX \e[0m\n"

clean: hello
	@echo "\e[48;2;155;100;0;1m Clean SoLong dependencies \e[0m\n"
	@$(RM) ${FTPRINTF} ${LIBFT}
	@$(MAKE) --no-print-directory clean -C $(MINILIBX_PATH)
	@echo "\n\e[48;2;0;0;155;1m Done \e[0m\n"

fclean:	hello clean
	@echo "\e[48;2;155;100;0;1m Uninstall SoLong \e[0m\n"
	@$(RM) $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

re:	hello fclean all

debug: hello ${LIBFT} ${FTPRINTF} ${MINILIBX} ${GNL} ${SRC}
	cc ${SRC} -D DEBUG=1 ${MINILIBX} ${GNL} ${LIBFT} ${FTPRINTF} ${CFLAGS} -o $(NAME)

story:  ${STORY_MAP} $(NAME)
	@echo "\e[48;2;100;0;100;1m Good luck !! \e[0m\n"
	@for map in ${STORY_MAP}; do \
		echo "\e[48;2;100;0;100;1m Running $(NAME) with $$map Have fun !!\e[0m\n"; \
		./$(NAME) $$map; \
		if [ $$? -ne 1 ]; then \
			echo "\e[48;2;100;0;100;1m Ohhh, its sad :c \e[0m\n"; \
			exit 1; \
		fi; \
	echo "\e[48;2;100;0;100;1m GG !! \e[0m\n"; \
    done;

.PHONY: all clean fclean re lib debug story
