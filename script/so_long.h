/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:31 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/04 01:55:04 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Include all header
# include <math.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include "../modules/libft/libft.h"
# include "../modules/minilibx-linux/mlx.h"
# include "../modules/minilibx-linux/mlx_int.h"
# include "../modules/ft_printf/func/ft_printf.h"
# include "../modules/get_next_line/get_next_line_bonus.h"

//Set color strings
# define RED			"\x1B[31m"
# define GRN			"\x1B[32m"
# define YEL			"\x1B[33m"
# define RES			"\x1B[0m"

//Set return value
# define RETURN_ERROR	-1

//Set the Window size
# define WIDTH			960
# define HEIGHT			540

//Set the view size and pos
# define VIEW_X			50
# define VIEW_Y			50
# define VIEW_W			440
# define VIEW_H			440

//Set the hud size and pos
# define HUD_X			540
# define HUD_Y			20
# define HUD_W			400
# define HUD_H			500

//Set all sprites path
# define BG				"./sprites/saturn.xpm"
# define PLAYER			"./sprites/player/down1.xpm"
# define ROOM_BG		"./sprites/room_bg.xpm"
# define HUD_BG			"./sprites/hud_bg.xpm"

//Set player value and hitbox
# define PLAYER_FRAMES	4
# define DEFAULT_SPEED	2
# define DEFAULT_SPRINT	3
# define DEFAULT_HP		100
# define DEFAULT_INV_S	1
# define HITBOX_W		64
# define HITBOX_H		64

//Dev settings
# define DEBUG			0
/* ************************************************************************** */
/*  So_long custom struct                                                     */
/* ************************************************************************** */
typedef struct s_sprites_player
{
	t_img	*up[5];
	t_img	*down[5];
	t_img	*left[5];
	t_img	*right[5];
}	t_sprites_player;

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

typedef struct s_sprites
{
	t_img				*player;
	t_img				*bg;
	t_img				*hud_bg;
	t_img				*room_bg;
	t_sprites_player	*player_anim;
}	t_sprites;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	*player;
	t_control	*control;
	t_sprites	*img;
}	t_mlx_data;

/* ************************************************************************** */
/*  Main functions                                                            */
/* ************************************************************************** */
int		handle_input(int keysym, t_mlx_data *data);
int		handle_input_keyrelease(int keysym, t_mlx_data *data);
int		mlx_close(t_mlx_data *data);
void	data_init(t_mlx_data *data);

/* ************************************************************************** */
/*  Sprites Init functions                                                    */
/* ************************************************************************** */
int		sprites_init_player1(t_mlx_data *data);
int		sprites_init_player2(t_mlx_data *data);
void	sprite_clear_player(t_mlx_data *data);

/* ************************************************************************** */
/*  Clock functions                                                           */
/* ************************************************************************** */
int		mlx_clock(t_mlx_data *data);
void	mlx_render(t_mlx_data *data);
void	mlx_actions(t_mlx_data *data);

/* ************************************************************************** */
/*  Img functions                                                             */
/* ************************************************************************** */
void	mlx_put_background(t_mlx_data *data);
void	mlx_put_player(t_mlx_data *data, int x, int y);
void	mlx_put_room_bg(t_mlx_data *data);
void	mlx_put_hud_bg(t_mlx_data *data);
void	draw_image(t_img *img, t_mlx_data *data, int x_offset, int y_offset);

/* ************************************************************************** */
/*  Player functions                                                          */
/* ************************************************************************** */
//Player basics
void	player_init(t_mlx_data *data);
void	player_move(t_mlx_data *data);
void	player_move2(t_mlx_data *data);
void	player_set_amim(t_mlx_data *data, t_img **set);

/* ************************************************************************** */
/*  Other functions (fun)                                                     */
/* ************************************************************************** */
int		color_map(t_mlx_data *data, int w, int h);
#endif
