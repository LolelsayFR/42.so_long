# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 23:30:22 by emaillet          #+#    #+#              #
#    Updated: 2024/12/03 19:11:14 by emaillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long


SRC				=	script/main.c\
					script/player.c\
					script/render.c\
					script/img.c\
					script/map.c\
					script/init_sprite_player.c\
					script/fun.c


GNL_PATH		=	./modules/get_next_line
GNL				=	$(GNL_PATH)/get_next_line_bonus.c\
					$(GNL_PATH)/get_next_line_utils_bonus.c

LIBFT_PATH		=	./modules/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

FTPRINTF_PATH	=	./modules/ft_printf
FTPRINTF		=	$(FTPRINTF_PATH)/libftprintf.a

MINILIBX_PATH	=	./modules/minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

CFLAGS			=	-lXext -lX11 -Wall -Werror -Wextra -g -O0

all:	$(NAME)

lib: $(LIBFT) $(FTPRINTF) $(MINILIBX)

$(NAME): ${LIBFT} ${FTPRINTF} ${MINILIBX} ${GNL} ${SRC}
	@echo "\e[48;2;0;155;0;1m Compile Solong \e[0m\n"
	cc ${SRC} ${MINILIBX} ${GNL} ${LIBFT} ${FTPRINTF} ${CFLAGS} -o $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

$(LIBFT):
	@echo "\e[48;2;0;155;0;1m Make LIBFT \e[0m\n"
	@$(MAKE) --no-print-directory  -C $(LIBFT_PATH)
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

clean:
	@echo "\e[48;2;155;100;0;1m Clean SoLong dependencies \e[0m\n"
	@$(RM) ${FTPRINTF} ${LIBFT}
	@$(MAKE) --no-print-directory clean -C $(MINILIBX_PATH)
	@echo "\n\e[48;2;0;0;155;1m Done \e[0m\n"

fclean:	clean
	@echo "\e[48;2;155;100;0;1m Uninstall SoLong \e[0m\n"
	@$(RM) $(NAME)
	@echo "\e[48;2;0;0;155;1m Done \e[0m\n"

re:	fclean all

.PHONY: all clean fclean re lib
