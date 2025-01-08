/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:02:43 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/08 21:32:21 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_clock(t_mlx_data *data)
{
	if (data->map->isvalid == 0)
		return (ft_printf(RED"[MAP ERROR]\nRead above.\n"RES), mlx_close(data));
	usleep(1000000 / FPS);
	if (data->frames % FPS == 0 || data->frames == 0)
	{
		mlx_timer(data);
		mlx_hud_render(data);
	}
	data->frames++;
	mlx_render(data);
	mlx_actions(data, data->player->pos_x, data->player->pos_y);
	return (1);
}

void	mlx_render(t_mlx_data *data)
{
	room_render(data);
	enemy_render(data);
	mlx_put_exit(data);
	mlx_put_player(data, data->player->pos_x, data->player->pos_y);
	if (data->player->hp <= 0)
		mlx_close(data);
}

void	mlx_actions(t_mlx_data *data, int x, int y)
{
	if (data->player->hitted > 0)
	{
		if (data->player->hitted == 1 && data->player->hp > 0)
			data->player->hp -= data->ouch;
		data->player->hitted++;
		if (data->player->hitted == FPS)
			data->player->hitted = 0;
		mlx_hud_render(data);
	}
	hit_box_cross_init(data);
	action_cooldown(data);
	data->room->p_pos[0] = player_coordinate(x - VIEW_X);
	data->room->p_pos[1] = player_coordinate(y - VIEW_Y);
	data->room->p_pos[2] = player_coordinate(x - VIEW_X + HITBOX_W);
	data->room->p_pos[3] = player_coordinate(y - VIEW_Y + HITBOX_H);
	enemy_colider(data);
	player_move(data);
	player_actions(data);
}

void	mlx_put_exit(t_mlx_data *data)
{
	int	pos[2];

	pos[0] = ((data->map->end_pos[0] - (data->map->player_pos[0] - 1) * 4)
			* (3 * TILE_SIZE)) - TILE_SIZE + VIEW_X;
	pos[1] = ((data->map->end_pos[1] - (data->map->player_pos[1] - 1) * 4)
			* (3 * TILE_SIZE)) - TILE_SIZE + VIEW_Y;
	if ((pos[0] > VIEW_X && pos[0] < VIEW_W + VIEW_X)
		&& (pos[1] > VIEW_Y && pos[1] < VIEW_H + VIEW_Y))
		draw_image(data->img->trophy, data, pos[0], pos[1]);
}
