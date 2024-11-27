NAME			=	so_long


SRC				=	script/main.c\


GNL_PATH		=	modules/get_next_line
GNL				=	$(GNL_PATH)/get_next_line_bonus.c\
					$(GNL_PATH)/get_next_line_utils_bonus.c

LIBFT_PATH		=	modules/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

FTPRINTF_PATH	=	modules/ft_printf
FTPRINTF		=	$(FTPRINTF_PATH)/libftprintf.a

MINILIBX_PATH	=	modules/minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx_Linux.a

CFLAGS			=	-Wall -Werror -Wextra -lmlx -lXext -lX11

all:	$(NAME)

lib: $(LIBFT) $(FTPRINTF) $(MINILIBX)

$(NAME): ${LIBFT} ${FTPRINTF} ${MINILIBX} ${GNL} ${SRC}
	@echo "\e[48;2;0;100;0;1m Compile Solong \e[0m\n"
	@cc ${CFLAGS} ${SRC} ${GNL} ${LIBFT} ${FTPRINTF} ${MINILIBX} -o $(NAME)
	@echo "\e[48;2;0;0;100;1m Done \e[0m\n"

$(LIBFT):
	@echo "\e[48;2;0;100;0;1m Make LIBFT \e[0m\n"
	@$(MAKE) --no-print-directory -s -C $(LIBFT_PATH)
	@echo "\e[48;2;100;0;0;1m Clean LIBFT object \e[0m\n"
	@$(MAKE) --no-print-directory  clean -s -C $(LIBFT_PATH)
	@echo "\e[48;2;0;0;100;1m Done for LIBFT \e[0m\n"

$(FTPRINTF):
	@echo "\e[48;2;0;100;0;1m Make FT_PRINTF \e[0m\n"
	@$(MAKE) --no-print-directory -s -C $(FTPRINTF_PATH)
	@echo "\e[48;2;100;0;0;1m Clean FT_PRINTF object \e[0m\n"
	@$(MAKE) --no-print-directory clean -s -C $(FTPRINTF_PATH)
	@echo "\e[48;2;0;0;100;1m Done for FT_PRINTF \e[0m\n"

$(MINILIBX):
	@echo "\e[48;2;0;100;0;1m Make MINILIBX \e[0m\n"
	@$(MAKE) --no-print-directory -s -C $(MINILIBX_PATH)
	@echo "\n\e[48;2;0;0;100;1m Done for MINILIBX \e[0m\n"

clean:
	@echo "\e[48;2;100;0;0;1m Clean SoLong dependencies \e[0m\n"
	@$(RM) ${FTPRINTF} ${LIBFT} ${MINILIBX}
	@$(MAKE) --no-print-directory -s $(MINILIBX_PATH)
	@echo "\e[48;2;0;0;100;1m Done \e[0m\n"

fclean:	clean
	@echo "\e[48;2;100;0;0;1m Uninstall SoLong \e[0m\n"
	@$(RM) $(NAME)
	@echo "\e[48;2;0;0;100;1m Done \e[0m\n"

re:	fclean all


.PHONY: all clean fclean re lib
