/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:15:26 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/30 04:55:39 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	player_move(t_mlx_data *data)
{
	int	speed;

	speed = data->player->speed;
	if (data->control->sprint)
		speed = data->player->speed + data->player->sprint;
	if (data->control->up && !data->control->down)
	{
		data->updated = 1;
		data->player->pos_y -= speed;
	}
	if (data->control->down && !data->control->up)
	{
		data->updated = 1;
		data->player->pos_y += speed;
	}
	if (data->control->left && !data->control->right)
	{
		data->updated = 1;
		data->player->pos_x -= speed;
	}
	if (data->control->right && !data->control->left)
	{
		data->updated = 1;
		data->player->pos_x += speed;
	}
}
