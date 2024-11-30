/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:31 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/30 04:42:24 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include "../modules/libft/libft.h"
# include "../modules/minilibx-linux/mlx.h"
# include "../modules/minilibx-linux/mlx_int.h"
# include "../modules/ft_printf/func/ft_printf.h"
# include "../modules/get_next_line/get_next_line_bonus.h"

# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define RES  "\x1B[0m"

# define RETURN_ERROR	-1
# define WIDTH			960
# define HEIGHT			540
# define BACKGROUND		"./sprites/saturn.xpm"
# define PLAYER			"./sprites/open.xpm"
# define DEFAULT_SPEED	2
# define DEFAULT_SPRINT	3
# define DEFAULT_HP		100
# define DEFAULT_INV_S	1

/* ************************************************************************** */
/*  So_long custom struct                                                     */
/* ************************************************************************** */
typedef struct s_control
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	sprint;
	int	primary;
	int	secondary;
}	t_control;

typedef struct s_inventory
{
	int	size;
	int	obj1;
	int	obj2;
	int	obj3;
	int	obj4;
	int	knife;
	int	pistol;
	int	bag;
	int	heal;
}	t_inventory;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	int			speed;
	int			sprint;
	int			hp;
	int			item;
	t_inventory	*inventory;
}	t_player;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	*player;
	t_control	*control;
	int			updated;
}	t_mlx_data;

/* ************************************************************************** */
/*  Main functions                                                            */
/* ************************************************************************** */
int		handle_input(int keysym, t_mlx_data *data);
int		handle_input_keyrelease(int keysym, t_mlx_data *data);
int		mlx_close(t_mlx_data *data);
void	data_init(t_mlx_data *data);

/* ************************************************************************** */
/*  Render  functions                                                         */
/* ************************************************************************** */
int		mlx_render(t_mlx_data *data);

/* ************************************************************************** */
/*  Img functions                                                             */
/* ************************************************************************** */
void	mlx_put_background(t_mlx_data *data);
void	mlx_put_player(t_mlx_data *data, int x, int y);

/* ************************************************************************** */
/*  Player functions                                                          */
/* ************************************************************************** */
void	player_init(t_mlx_data *data);
void	player_move(t_mlx_data *data);

/* ************************************************************************** */
/*  Other functions (fun)                                                     */
/* ************************************************************************** */
int		color_map(t_mlx_data *data, int w, int h);
#endif
