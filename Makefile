NAME			=	so_long


SRC			=	script/main.c\


LIBFT_PATH		=	lib/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

FTPRINTF_PATH	=	lib/ft_printf
FTPRINTF		=	$(FTPRINTF_PATH)/libftprintf.a

GNL_PATH		=	lib/ft_printf
GNL				=	$(GNL_PATH)/li.a

CFLAGS			=	-Wall -Werror -Wextra

all:	$(NAME_C) $(NAME_S) 

lib: $(LIBFT) $(FTPRINTF)

$(NAME_C): ${LIBFT} ${FTPRINTF} ${SRC_C}
	cc ${CFLAGS} ${SRC_C} ${LIBFT} ${FTPRINTF} -o $(NAME_C)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) clean -C $(LIBFT_PATH)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_PATH)
	$(MAKE) clean -C $(FTPRINTF_PATH)

$(GNL):
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) clean -C $(LIBFT_PATH)

clean:
	$(RM) ${FTPRINTF} ${LIBFT}

fclean:	clean
	$(RM) $(NAME_C) $(NAME_S)

re:	fclean all


.PHONY: all clean fclean re lib
