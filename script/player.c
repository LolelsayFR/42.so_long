/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:15:26 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/08 12:02:04 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_mlx_data *data)
{
	int	speed;

	speed = data->player->speed;
	if (data->control->sprint)
		speed = data->player->speed + data->player->sprint;
	if (data->control->up && !data->control->down && player_hitbox(data,
			data->player->pos_x, data->player->pos_y - speed))
		data->player->pos_y -= speed;
	if (data->control->down && !data->control->up && player_hitbox(data,
			data->player->pos_x, data->player->pos_y + speed))
		data->player->pos_y += speed;
	if (data->control->left && !data->control->right && player_hitbox(data,
			data->player->pos_x - speed, data->player->pos_y))
		data->player->pos_x -= speed;
	if (data->control->right && !data->control->left && player_hitbox(data,
			data->player->pos_x + speed, data->player->pos_y))
		data->player->pos_x += speed;
	player_move2(data);
}

void	player_move2(t_mlx_data *data)
{
	if (data->control->up && !data->control->down)
		player_set_amim(data, data->img->player_anim->up);
	else if (data->control->down && !data->control->up)
		player_set_amim(data, data->img->player_anim->down);
	else if (data->control->right && !data->control->left)
		player_set_amim(data, data->img->player_anim->right);
	else if (data->control->left && !data->control->right)
		player_set_amim(data, data->img->player_anim->left);
	else
		data->img->player = data->img->player_anim->down[0];
	player_mapmove(data);
}

void	player_set_amim(t_mlx_data *data, t_img **set)
{
	static int	i = 0;
	static int	j = 0;
	int			interval;

	j++;
	if (data->control->sprint == 1)
		interval = 1;
	else
		interval = 2;
	if (i < PLAYER_FRAMES)
	{
		if (j >= interval)
		{
			data->img->player = set[i];
			i++;
			j = 0;
			if (i == 1)
				data->player->player_step++;
		}
	}
	else
	{
		i = 0;
		data->img->player = set[i];
	}
}

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
