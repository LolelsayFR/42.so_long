/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:19:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 09:50:20 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_create(t_mlx_data *data, char c, int x, int y)
{
	static int	id = 0;
	t_enemy		*new;

	if (c != M_ENEMY && c != M_SPIKE)
		return ;
	new = malloc(sizeof(t_enemy));
	new->type = c;
	new->move[0] = 0;
	new->move[1] = 0;
	new->spawn[0] = x;
	new->spawn[1] = y;
	new->active = 0;
	new->alive = 1;
	new->speed = DEFAULT_SPEED / 2;
	if (c == M_ENEMY)
		new->damage = 2;
	else
		new->damage = 1;
	data->enemy[id] = new;
	id++;
}

void	enemy_move(t_mlx_data *data, int id)
{
	if (data->enemy[id]->pos[0] > data->player->pos_x)
		data->enemy[id]->move[0] -= data->enemy[id]->speed;
	if (data->enemy[id]->pos[0] < data->player->pos_x + HITBOX_W)
		data->enemy[id]->move[0] += data->enemy[id]->speed;
	if (data->enemy[id]->pos[1] > data->player->pos_y)
		data->enemy[id]->move[1] -= data->enemy[id]->speed;
	if (data->enemy[id]->pos[1] < data->player->pos_y + HITBOX_H)
		data->enemy[id]->move[1] += data->enemy[id]->speed;
}

void	enemy_render_utils(t_mlx_data *data, int i, t_enemy	**e, int y)
{
	if (e[i]->type == M_ENEMY && e[i]->alive == 1
		&& (e[i]->pos[0] > VIEW_X + 14
			&& e[i]->pos[0] < VIEW_W + VIEW_X - 28)
		&& (e[i]->pos[1] > VIEW_Y + 21
			&& e[i]->pos[1] < VIEW_H + VIEW_Y - 42))
	{
		draw_image(data->img->enemy, data, e[i]->pos[0]
			- 7, e[i]->pos[1] - 21 + y);
		data->enemy[i]->active = 1;
	}
}

void	enemy_render(t_mlx_data *data)
{
	int		i;
	int		y;
	t_enemy	**e;

	y = 0;
	i = 0;
	e = data->enemy;
	while (e[i] != NULL)
	{
		if (y < 5)
			y++;
		if (y > 5)
			y--;
		e[i]->pos[0] = ((e[i]->spawn[0] - (data->map->player_pos[0] - 1) * 4)
				* (3 * TILE_SIZE)) - (TILE_SIZE / 2) + VIEW_X + e[i]->move[0];
		e[i]->pos[1] = ((e[i]->spawn[1] - (data->map->player_pos[1] - 1) * 4)
				* (3 * TILE_SIZE)) - (TILE_SIZE / 2) + VIEW_Y + e[i]->move[1];
		if (e[i]->type == M_SPIKE
			&& (e[i]->pos[0] > VIEW_X && e[i]->pos[0] < VIEW_W + VIEW_X)
			&& (e[i]->pos[1] > VIEW_Y && e[i]->pos[1] < VIEW_H + VIEW_Y))
			draw_image(data->img->spike, data, e[i]->pos[0]
				- 11, e[i]->pos[1] - 14);
		enemy_render_utils(data, i, e, y);
		i++;
	}
}

void	enemy_free(t_mlx_data *data)
{
	int		i;

	i = 0;
	while (data->enemy[i])
	{
		free(data->enemy[i]);
		i++;
	}
	free(data->enemy);
}
