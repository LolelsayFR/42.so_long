/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:30:28 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/07 07:49:31 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	data_init(t_mlx_data *data, char *map_path)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(-1);
	data->control = malloc(sizeof(t_control));
	data->img = malloc(sizeof(t_sprites));
	data->map = malloc(sizeof(t_map));
	data->control->up = 0;
	data->control->down = 0;
	data->control->right = 0;
	data->control->left = 0;
	data->control->primary = 0;
	data->control->secondary = 0;
	data->control->sprint = 0;
	data->map->path = map_path;
	sprites_init_player1(data);
	sprites_init_door1(data);
	player_init(data);
	map_init(data);
}

void	player_init(t_mlx_data *data)
{
	data->player = malloc(sizeof(t_player));
	data->player->inventory = malloc(sizeof(t_inventory));
	data->player->inventory->size = DEFAULT_INV_S;
	data->player->speed = DEFAULT_SPEED;
	data->player->sprint = DEFAULT_SPRINT;
	data->player->hp = DEFAULT_HP;
	data->player->pos_x = 100;
	data->player->pos_y = 100;
	data->map->player_pos[0] = 1;
	data->map->player_pos[1] = 1;
}
