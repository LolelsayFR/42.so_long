/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:02:43 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/18 14:27:09 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mlx_clock(t_mlx_data *data)
{
	usleep(1000000 / FPS);
	if (data->state != 0)
		return (popup_hud(data), 1);
	if (data->frames % FPS == 0 || data->frames == 0)
	{
		mlx_timer(data);
		mlx_hud_render(data);
	}
	if (data->inpopup == 1)
		data->inpopup = 0;
	data->frames++;
	mlx_render(data);
	mlx_actions(data, data->player->pos_x, data->player->pos_y);
	if (!data->map->isvalid || !data->floodfill->isvalid)
		return (data->state = -1, mlx_close(data));
	return (1);
}

void	mlx_render(t_mlx_data *data)
{
	room_render(data);
	enemy_render(data);
	mlx_put_exit(data);
	mlx_put_player(data, data->player->pos_x, data->player->pos_y);
	if (data->player->hp <= 0)
		data->state = 2;
	if (data->control->heal && data->player->potion
		&& data->player->hp < DEFAULT_HP)
	{
		data->control->heal = 0;
		data->player->potion--;
		data->map->potion--;
		data->player->taken = 1;
		data->player->hp++;
	}
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

	if (data->state != 0)
		return ;
	pos[0] = ((data->map->end_pos[0] - (data->map->player_pos[0] - 1) * 4)
			* (3 * TILE_SIZE)) - TILE_SIZE + VIEW_X;
	pos[1] = ((data->map->end_pos[1] - (data->map->player_pos[1] - 1) * 4)
			* (3 * TILE_SIZE)) - TILE_SIZE + VIEW_Y;
	if (data->map->end_pos[0] % 4 == 0 || data->map->end_pos[1] % 4 == 0)
	{
		draw_player(data->img->trophy, data, pos[0] + TILE_SIZE, pos[1]);
		draw_player(data->img->trophy, data, pos[0] - TILE_SIZE, pos[1]);
		draw_player(data->img->trophy, data, pos[0], pos[1] + TILE_SIZE);
		draw_player(data->img->trophy, data, pos[0], pos[1] - TILE_SIZE);
	}
	else
		draw_player(data->img->trophy, data, pos[0], pos[1]);
}
