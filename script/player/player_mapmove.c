/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mapmove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:15:26 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 10:32:02 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_mapmove(t_mlx_data *data)
{
	if (data->player->pos_y > VIEW_H + VIEW_Y - (HITBOX_H))
	{
		if (data->map->player_pos[1] <= data->map->size_y / 4)
		{
			data->player->pos_y = VIEW_Y;
			data->map->player_pos[1]++;
		}
		else
			data->player->pos_y = VIEW_H + VIEW_Y - (HITBOX_H);
	}
	else if (data->player->pos_y < VIEW_Y)
	{
		if (data->map->player_pos[1] > 1)
		{
			data->player->pos_y = VIEW_H + VIEW_Y - (HITBOX_H);
			data->map->player_pos[1]--;
		}
		else
			data->player->pos_y = VIEW_Y;
	}
	player_mapmove2(data);
}

void	player_mapmove2(t_mlx_data *data)
{
	if (data->player->pos_x > VIEW_W + VIEW_X - (HITBOX_H))
	{
		if (data->map->player_pos[0] < data->map->size_x / 4)
		{
			data->player->pos_x = VIEW_X;
			data->map->player_pos[0]++;
		}
		else
			data->player->pos_x = VIEW_W + VIEW_X - (HITBOX_H);
	}
	else if (data->player->pos_x < VIEW_X)
	{
		if (data->map->player_pos[0] > 1)
		{
			data->player->pos_x = VIEW_W + VIEW_X - (HITBOX_H);
			data->map->player_pos[0]--;
		}
		else
			data->player->pos_x = VIEW_X;
	}
}
