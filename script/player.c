/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:15:26 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/30 01:43:25 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_init(t_mlx_data *data)
{
	data->player->speed = DEFAULT_SPEED;
	data->player->sprint = DEFAULT_SPRINT;
	data->player->pos_x = 100;
	data->player->pos_y = 100;
}

void	player_move(t_mlx_data *data)
{
	int	speed;

	speed = data->player->speed;
	if (data->control->shift)
		speed = data->player->speed + data->player->sprint;
	if (data->control->up)
	{
		data->updated = 1;
		data->player->pos_y -= speed;
	}
	if (data->control->down)
	{
		data->updated = 1;
		data->player->pos_y += speed;
	}
	if (data->control->left)
	{
		data->updated = 1;
		data->player->pos_x -= speed;
	}
	if (data->control->right)
	{
		data->updated = 1;
		data->player->pos_x += speed;
	}
}
