/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:31 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/06 21:14:11 by emaillet         ###   ########.fr       */
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
# define TILE_SIZE		40

//Set the hud size and pos
# define HUD_X			539
# define HUD_Y			20
# define HUD_W			400
# define HUD_H			500

//Set all base sprites path
# define BG				"./sprites/background.xpm"
# define PLAYER			"./sprites/player/down1.xpm"
# define ROOM_BG		"./sprites/room_bg.xpm"
# define HUD_BG			"./sprites/hud_bg.xpm"
# define E_TYPE_GHOST	"./sprites/enemy.xpm"
# define E_TYPE_SPIKE	"./sprites/spikes.xpm"

//Set player value and hitbox
# define PLAYER_FRAMES	4
# define DEFAULT_SPEED	4
# define DEFAULT_SPRINT	4
# define DEFAULT_HP		100
# define DEFAULT_INV_S	1
# define COOLDOWN		10
# define HITBOX_W		64
# define HITBOX_H		64

//Set the map charset
# define MAP_SET	"W:~.ED@$&F"
# define MAP_COLIDE	"WDE"
# define MAP_ACTION	":~F"
# define MAP_OPEN_DOOR	"de"
# define MAP_CLOSE_DOOR	"DE"
# define M_WALL			'W'
# define M_CH_OBJ_C		':'
# define M_CH_OBJ_O		';'
# define M_CH_HP_C		'~'
# define M_CH_HP_O		'-'
# define M_FLOOR		'.'
# define M_DOOR_OBJ_C	'E'
# define M_DOOR_OBJ_O	'e'
# define M_DOOR_C		'D'
# define M_DOOR_O		'd'
# define M_PLAYER		'@'
# define M_ENEMY		'$'
# define M_SPIKE		'&'
# define M_FINISH		'F'
# define M_NOT_VISITED	'*'

//Dev settings
# define PTH			"./sprites/"
# define DEBUG			0
# define FPS			60

/* ************************************************************************** */
/*  So_long custom struct                                                     */
/* ************************************************************************** */
typedef struct s_sprites_player
{
	t_img				*up[5];
	t_img				*down[5];
	t_img				*left[5];
	t_img				*right[5];
}	t_sprites_player;

typedef struct s_sprites_tilemap
{
	t_img				*door_up[5];
	t_img				*door_down[5];
	t_img				*door_left[5];
	t_img				*door_right[5];
	t_img				*end_up[5];
	t_img				*end_down[5];
	t_img				*end_left[5];
	t_img				*end_right[5];
	t_img				*wall[9];
	t_img				*chest[3];
	t_img				*red_chest[3];
	t_img				*floor[10];
	t_img				*error;
	t_img				*voids;
}	t_sprites_tilemap;

typedef struct s_control
{
	int					up;
	int					down;
	int					left;
	int					right;
	int					sprint;
	int					primary;
}	t_control;

typedef struct s_player
{
	int					pos_x;
	int					pos_y;
	int					speed;
	int					sprint;
	int					hp;
	int					obj;
	int					player_step;
	int					cooldown;
	int					can_use;
}	t_player;

typedef struct s_enemy
{
	int					room_pos[3];
	int					screen_pos[3];
	int					speed;
	char				*type;
	int					player_step;
}	t_enemy;

typedef struct s_room
{
	char				map[6][7];
	int					p_pos[5];
	int					r_pos[3];
	int					enemy_pos[3];
}	t_room;

typedef struct s_map
{
	t_list				*temp_map;
	char				**map;
	char				**visited_map;
	char				*path;
	int					size_x;
	int					size_y;
	int					end_pos[3];
	int					end;
	int					player_pos[3];
	int					player;
	int					obj;
	int					isvalid;
}	t_map;

typedef struct s_sprites
{
	t_img				*player;
	t_img				*bg;
	t_img				*hud_bg;
	t_img				*room_bg;
	t_sprites_player	*player_anim;
	t_sprites_tilemap	*tilemap;
}	t_sprites;

typedef struct s_mlx_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_player			*player;
	t_enemy				**enemy;
	t_control			*control;
	t_sprites			*img;
	t_room				*room;
	t_map				*map;
	char				*timer;
	char				*obj;
}	t_mlx_data;

/* ************************************************************************** */
/*  Main functions                                                            */
/* ************************************************************************** */
int		handle_input(int keysym, t_mlx_data *data);
int		handle_input_keyrelease(int keysym, t_mlx_data *data);
int		mlx_close(t_mlx_data *data);
void	data_init(t_mlx_data *data, char *map_path);

/* ************************************************************************** */
/*  Sprites Init functions                                                    */
/* ************************************************************************** */
int		sprites_init_player1(t_mlx_data *data);
int		sprites_init_player2(t_mlx_data *data);
void	sprite_clear_player(t_mlx_data *data);
int		sprites_init_door1(t_mlx_data *data);
int		sprites_init_door2(t_mlx_data *data);
int		sprites_init_door3(t_mlx_data *data);
int		sprites_init_door4(t_mlx_data *data);
int		sprites_init_wall(t_mlx_data *data);
int		sprites_init_floors(t_mlx_data *data);
int		sprites_init_other(t_mlx_data *data);
void	sprite_clear_tilemap1(t_mlx_data *data);
void	sprite_clear_tilemap2(t_mlx_data *data);
void	sprite_clear_tilemap3(t_mlx_data *data);

/* ************************************************************************** */
/*  Clock functions                                                           */
/* ************************************************************************** */
int		mlx_clock(t_mlx_data *data);
void	mlx_render(t_mlx_data *data);
void	mlx_actions(t_mlx_data *data, int x, int y);
void	mlx_hud_render(t_mlx_data *data);

/* ************************************************************************** */
/*  Img functions                                                             */
/* ************************************************************************** */
void	mlx_put_background(t_mlx_data *data);
void	mlx_put_player(t_mlx_data *data, int x, int y);
void	mlx_put_room_bg(t_mlx_data *data);
void	mlx_put_hud_bg(t_mlx_data *data);
void	mlx_put_tiles(t_mlx_data *data, t_img *tile, int x, int y);
void	draw_image(t_img *img, t_mlx_data *data, int x_offset, int y_offset);

/* ************************************************************************** */
/*  Player functions                                                          */
/* ************************************************************************** */
//Player basics
void	player_init(t_mlx_data *data);
void	player_move(t_mlx_data *data);
void	player_move2(t_mlx_data *data);
void	player_mapmove(t_mlx_data *data);
void	player_mapmove2(t_mlx_data *data);
void	player_set_amim(t_mlx_data *data, t_img **set);
int		player_hitbox(t_mlx_data *data, int x, int y);
int		player_hitbox_door(t_mlx_data *data, int x, int y, int *xy);
int		player_colider(t_mlx_data *data, int x, int y);
int		player_coordinate(int coor);
int		door_check(int x, int y);
void	player_actions(t_mlx_data *data);
void	door_action(t_mlx_data *data, int hit[5][3]);
void	chest_action(t_mlx_data *data, int x, int y);

/* ************************************************************************** */
/*  Enemy functions                                                           */
/* ************************************************************************** */
t_enemy	*enemy_create(t_mlx_data *data, char c, int x, int y);
t_enemy	*enemy_kill(t_mlx_data *data, int id);

/* ************************************************************************** */
/*  Map functions                                                             */
/* ************************************************************************** */
//Map Init, free and Check
void	check_map_path(char *str);
int		map_init(t_mlx_data *data);
int		map_check(t_mlx_data *data);
int		map_check2(t_mlx_data *data);
int		map_paste(t_mlx_data *data);
int		map_paste2(t_mlx_data *data, int x, int y);
int		map_free(t_mlx_data *data);
void	map_print(char **map);
void	map_data_init(t_mlx_data *data, char c, int x, int y);

//Map decors
void	map_decor(t_mlx_data *data);
void	map_tilepos(t_mlx_data *data, int x, int y, char c);
void	map_wallpos(t_mlx_data *data, int x, int y);
void	map_wallpos2(t_mlx_data *data, int x, int y, int *xy);
void	map_floorpos(t_mlx_data *data, int x, int y);
void	map_floorpos2(t_mlx_data *data, int x, int y);
void	map_chestpos(t_mlx_data *data, int x, int y, char c);
void	map_chestpos2(t_mlx_data *data, int x, int y, int *xy);
void	map_doorpos(t_mlx_data *data, int x, int y, char c);
void	map_doorpos2(t_mlx_data *data, int x, int y, int *xy);
void	map_doorpos3(t_mlx_data *data, int x, int y, int *xy);
void	map_errorpos(t_mlx_data *data, int x, int y);
void	map_voidpos(t_mlx_data *data, int x, int y);
//Room Functions
int		room_render(t_mlx_data *data);
t_room	*room_clear(t_room *room);
t_room	*room_paste(t_room *room, t_map *map, int *ppos);
void	visited_paste(t_map *map, int *ppos);
void	room_print(t_room *room);
void	modified_room(t_room *room, t_map *map, int *ppos);

/* ************************************************************************** */
/*  Other functions                                                           */
/* ************************************************************************** */
int		color_map(t_mlx_data *data, int w, int h);
void	action_cooldown(t_mlx_data *data);
void	mlx_timer(t_mlx_data *data);
#endif
