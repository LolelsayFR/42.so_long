/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:30:28 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/30 18:27:41 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_init(t_mlx_data *data, char *map_path)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(-1);
	data->control = ft_calloc(1, sizeof(t_control));
	data->img = ft_calloc(1, sizeof(t_sprites));
	data->map = ft_calloc(1, sizeof(t_map));
	data->room = ft_calloc(1, sizeof(t_room));
	data->map->isvalid = 0;
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
	data->map->isvalid = map_init(data);
	data->room->r_pos[0] = -1;
	data->room->r_pos[1] = -1;
}

void	player_init(t_mlx_data *data)
{
	data->player = ft_calloc(1, sizeof(t_player));
	data->player->inventory = ft_calloc(1, sizeof(t_inventory));
	data->player->inventory->size = DEFAULT_INV_S;
	data->player->speed = DEFAULT_SPEED;
	data->player->sprint = DEFAULT_SPRINT;
	data->player->hp = DEFAULT_HP;
	data->player->pos_x = 100;
	data->player->pos_y = 100;
	data->player->player_step = 0;
	data->map->player_pos[0] = 1;
	data->map->player_pos[1] = 1;
}
