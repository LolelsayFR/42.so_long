/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:15:26 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/04 00:42:03 by emaillet         ###   ########.fr       */
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
		data->player->pos_y -= speed;
	if (data->control->down && !data->control->up)
		data->player->pos_y += speed;
	if (data->control->left && !data->control->right)
		data->player->pos_x -= speed;
	if (data->control->right && !data->control->left)
		data->player->pos_x += speed;
	if (data->player->pos_x > VIEW_W + VIEW_X - HITBOX_W)
		data->player->pos_x = VIEW_W + VIEW_X - HITBOX_W;
	else if (data->player->pos_x < VIEW_X)
		data->player->pos_x = VIEW_X;
	if (data->player->pos_y > VIEW_H + VIEW_Y - HITBOX_H)
		data->player->pos_y = VIEW_H + VIEW_Y - HITBOX_H;
	else if (data->player->pos_y < VIEW_Y)
		data->player->pos_y = VIEW_Y;
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
}

void	player_set_amim(t_mlx_data *data, t_img **set)
{
	static int	i = 0;
	static int	j = 0;
	int			interval;

	interval = 0;
	j++;
	if (data->control->sprint == 1)
		interval = 1;
	else
		interval = 3;
	if (i < PLAYER_FRAMES)
	{
		if (j >= interval)
		{
			data->img->player = set[i];
			i++;
			j = 0;
		}
	}
	else
		i = 0;
}
