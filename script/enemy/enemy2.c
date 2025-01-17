/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:19:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/17 23:56:11 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	so_scream(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 5)
	{
		draw_image(data->img->anim_screamer[i], data, VIEW_X, VIEW_Y);
		i++;
		if (i >= 3)
		{
			j++;
			i = 2;
		}
	}
}

void	enemy_colider(t_mlx_data *data)
{
	int		i;

	i = 0;
	while (data->enemy[i])
	{
		if (data->enemy[i]->alive && data->enemy[i]->active
			&& data->enemy[i]->type == M_ENEMY)
			enemy_move(data, i);
		if (data->enemy[i]->alive
			&& (data->enemy[i]->pos[0] > data->player->pos_x - 10
				&& data->enemy[i]->pos[0] < data->player->pos_x + HITBOX_W + 10)
			&& (data->enemy[i]->pos[1] > data->player->pos_y - 10
				&& data->enemy[i]->pos[1] < data->player->pos_y + HITBOX_H + 10)
			&& data->player->hitted == 0)
		{
			if (data->enemy[i]->type == M_ENEMY)
			{
				data->enemy[i]->alive = 0;
				so_scream(data);
			}
			data->ouch = data->enemy[i]->damage;
			data->player->hitted = 1;
		}
		i++;
	}
}

void	spike_render(t_enemy **e, t_mlx_data *data, int i)
{
	if (e[i]->type == M_SPIKE
		&& ((e[i]->spawn[0] % 4 == 0 || !e[i]->spawn[1] % 4 == 0)
			&& !(e[i]->pos[0] < VIEW_X + VIEW_W && e[i]->pos[0] > VIEW_X
				&& e[i]->pos[1] < VIEW_Y + VIEW_H && e[i]->pos[1] > VIEW_Y)))
	{
		draw_player(data->img->spike, data, e[i]->pos[0]
			+ TILE_SIZE - 11, e[i]->pos[1] - 14);
		draw_player(data->img->spike, data, e[i]->pos[0]
			- TILE_SIZE - 11, e[i]->pos[1] - 14);
		draw_player(data->img->spike, data, e[i]->pos[0]
			- 11, e[i]->pos[1] - 14 + TILE_SIZE);
		draw_player(data->img->spike, data, e[i]->pos[0]
			- 11, e[i]->pos[1] - 14 - TILE_SIZE);
	}
	else if (e[i]->type == M_SPIKE)
		draw_player(data->img->spike, data, e[i]->pos[0]
			- 11, e[i]->pos[1] - 14);
}
