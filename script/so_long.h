/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:31 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/18 18:32:26 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef DEBUG
#  define DEBUG 0
# endif

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
# define RETURN_SUCCESS	1

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
# define DEFAULT_HP		8
# define COOLDOWN		10
# define HITBOX_W		64
# define HITBOX_H		64

//Set the map charset
# define MAP_SET		"W:~.ED@$&Fde;-"
# define MAP_COLIDE		"WDE"
# define MAP_ACTION		":~F"
# define MAP_CORN_ERROR	":;-~FdeDE&$@"
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
# define M_FLOOD		'+'
# define M_FLOOD2		'x'

//Dev settings
# define PTH			"./sprites/"
# define FPS			60
# define MINMAP_X		576
# define MINMAP_Y		142
# define MINMAP_MX		898
# define MINMAP_MY		289

/* ************************************************************************** */
/*  So_long custom struct                                                     */
/* ************************************************************************** */
typedef struct s_sprites_player
{
	t_img				*up[5];
	t_img				*down[5];
	t_img				*left[5];
	t_img				*right[5];
	t_img				*take;
	t_img				*dead;
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

typedef struct s_sprites_minimap
{
	t_img				*wall;
	t_img				*door_o;
	t_img				*door2_o;
	t_img				*door_c;
	t_img				*door2_c;
	t_img				*enemy;
	t_img				*spike;
	t_img				*chest_c;
	t_img				*chest_o;
	t_img				*chest2_o;
	t_img				*chest2_c;
	t_img				*player;
	t_img				*final;
	t_img				*floor;
	t_img				*player_bg;
}	t_sprites_minimap;

typedef struct s_control
{
	int					up;
	int					down;
	int					left;
	int					right;
	int					sprint;
	int					primary;
	int					heal;
}	t_control;

typedef struct s_player
{
	int					pos_x;
	int					pos_y;
	int					speed;
	int					sprint;
	int					hp;
	int					obj;
	int					potion;
	int					player_step;
	int					cooldown;
	int					can_use;
	int					hitted;
	int					taken;
	int					spawn[2];
}	t_player;

typedef struct s_enemy
{
	int					spawn[2];
	int					pos[2];
	int					move[2];
	int					speed;
	char				type;
	int					active;
	int					alive;
	int					damage;
}	t_enemy;

typedef struct s_room
{
	char				map[6][7];
	int					p_pos[5];
	int					r_pos[2];
	int					enemy_pos[2];
}	t_room;

typedef struct s_flood
{
	int					obj;
	char				**map;
	char				isvalid;
}	t_flood;

typedef struct s_map
{
	t_list				*temp_map;
	char				**map;
	char				**visited_map;
	char				*path;
	int					size_x;
	int					size_y;
	int					end_pos[2];
	int					end;
	int					player_pos[2];
	int					player;
	int					obj;
	int					enemy;
	int					potion;
	int					isvalid;
}	t_map;

typedef struct s_sprites
{
	t_img				*player;
	t_img				*bg;
	t_img				*hud_bg;
	t_img				*room_bg;
	t_img				*heart;
	t_img				*spike;
	t_img				*enemy;
	t_img				*trophy;
	t_img				*rope;
	t_img				*relic[8];
	t_sprites_player	*player_anim;
	t_img				*anim_screamer[3];
	t_img				*potion;
	t_sprites_tilemap	*tilemap;
	t_img				*shield;
	t_img				*popup[3];
	t_img				*menu;
	t_sprites_minimap	*mini;
}	t_sprites;

typedef struct s_logs
{
	t_list				*map;
	t_list				*checker;
	t_list				*floodfill;
	t_list				*other;
}	t_logs;

typedef struct s_mlx_data
{
	unsigned long long	frames;
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
	char				*potion;
	int					hc[5][2];
	int					ouch;
	int					state;
	int					inpopup;
	t_flood				*floodfill;
	t_logs				*logs;
}	t_mlx_data;

/* ************************************************************************** */
/*  Main functions                                                            */
/* ************************************************************************** */
int		handle_input(int keysym, t_mlx_data *data);
int		handle_input_keyrelease(int keysym, t_mlx_data *data);
int		mlx_close(t_mlx_data *data);
void	data_init(t_mlx_data *data, char *map_path);
void	data_init2(t_mlx_data *data);
void	pause_handle_input(t_mlx_data *data);
void	end_handle_input(t_mlx_data *data);

/* ************************************************************************** */
/*  Sprites Init functions                                                    */
/* ************************************************************************** */
int		sprites_init_ui(t_mlx_data *data);
int		sprites_init_ui2(t_mlx_data *data);
int		sprites_init_minimap(t_mlx_data *data);
int		sprites_init_minimap2(t_mlx_data *data);
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
void	sprite_clear_minimap(t_mlx_data *data);
void	sprite_clear_ui(t_mlx_data *data);
void	mlx_put_background(t_mlx_data *data);
void	mlx_put_player(t_mlx_data *data, int x, int y);
void	mlx_put_room_bg(t_mlx_data *data);
void	mlx_put_hud_bg(t_mlx_data *data);
void	mlx_put_tiles(t_mlx_data *data, t_img *tile, int x, int y);
void	draw_image(t_img *img, t_mlx_data *data, int x_offset, int y_offset);
void	draw_player(t_img *img, t_mlx_data *data, int x_offset, int y_offset);
void	popup_hud(t_mlx_data *data);

/* ************************************************************************** */
/*  Clock functions                                                           */
/* ************************************************************************** */
int		mlx_clock(t_mlx_data *data);
void	mlx_render(t_mlx_data *data);
void	mlx_actions(t_mlx_data *data, int x, int y);
void	mlx_hud_render(t_mlx_data *data);
void	mlx_hud_render2(t_mlx_data *data);
void	heart_hud(t_mlx_data *data);
void	hit_box_cross_init(t_mlx_data *data);

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
int		player_hitbox_door(t_mlx_data *data, int x, int y);
int		player_colider(t_mlx_data *data, int x, int y);
int		player_coordinate(int coor);
int		door_check(int x, int y);
void	player_actions(t_mlx_data *data);
void	door_action(t_mlx_data *data);
void	door_action2(t_mlx_data *data, int i);
void	chest_action(t_mlx_data *data, int x, int y);

/* ************************************************************************** */
/*  Enemy functions                                                           */
/* ************************************************************************** */
void	enemy_create(t_mlx_data *data, char c, int x, int y);
void	enemy_move(t_mlx_data *data, int id);
void	enemy_render(t_mlx_data *data);
void	enemy_free(t_mlx_data *data);
void	enemy_colider(t_mlx_data *data);
void	enemy_render_utils(t_mlx_data *data, int i, t_enemy	**e, int y);
void	so_scream(t_mlx_data *data);
void	spike_render(t_enemy **e, t_mlx_data *data, int i);

/* ************************************************************************** */
/*  Map functions                                                             */
/* ************************************************************************** */
//Map Init, free and Check
void	check_map_path(char *str);
int		map_init(t_mlx_data *data);
int		map_check(t_mlx_data *data, int i, int j);
int		map_check2(t_mlx_data *data);
int		map_paste(t_mlx_data *data);
int		map_paste2(t_mlx_data *data, int x, int y);
int		map_free(t_mlx_data *data);
void	map_print(char **map, t_mlx_data *data);
void	map_data_init(t_mlx_data *data, char c, int x, int y);
int		map_paste_dup(t_mlx_data *data);
int		expand_map(t_mlx_data *data, int new_size_x, int new_size_y);
int		expand_init(char ***map, char ***visited, int size_y);
void	expand_fill(t_mlx_data *data, char **map, char **visited, int sizes[2]);
void	ex_fill_line(t_mlx_data *data, char **map, char **visited, int pos[2]);
void	expand_free_old(t_mlx_data *data);
int		floodfill(t_mlx_data *data, int x, int y);
char	**tabdup(char **map);

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
void	mlx_put_exit(t_mlx_data *data);
void	map_doorpos_middle(t_mlx_data *data, int x, int y, char c);
int		isdooropen(char c);

//Room Functions
int		room_render(t_mlx_data *data);
t_room	*room_clear(t_room *room);
t_room	*room_paste(t_room *room, t_map *map, int *ppos);
void	visited_paste(t_map *map, int *ppos);
void	room_print(t_room *room);
void	modified_room(t_room *room, t_map *map, int *ppos);

//Minimap Functions
void	minimap_print_one(t_mlx_data *data, int x, int y, char c);

/* ************************************************************************** */
/*  Other functions                                                           */
/* ************************************************************************** */
int		color_map(t_mlx_data *data, int w, int h);
void	action_cooldown(t_mlx_data *data);
void	mlx_timer(t_mlx_data *data);
int		check_rectangular(char **tab);
void	sl_logs(t_list *logs, char *str, ...);
void	sl_logs_init(t_mlx_data *data);
void	sl_logs_free(t_mlx_data *data);
void	sl_logs_print(t_list *lst);
void	sl_maplogs(t_mlx_data *data, char **tab);

#endif
