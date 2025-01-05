/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:02:43 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/05 02:49:36 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_clock(t_mlx_data *data)
{
	if (data->map->isvalid == 0)
		return (ft_printf(RED"[MAP ERROR]\nRead above.\n"RES), mlx_close(data));
	usleep(1000000 / 60);
	room_render(data);
	mlx_actions(data, data->player->pos_x, data->player->pos_y);
	mlx_render(data);
	return (1);
}

void	mlx_render(t_mlx_data *data)
{
	mlx_put_player(data, data->player->pos_x, data->player->pos_y);
}

void	mlx_actions(t_mlx_data *data, int x, int y)
{
	data->room->p_pos[0] = player_coordinate(x - VIEW_X);
	data->room->p_pos[1] = player_coordinate(y - VIEW_Y);
	data->room->p_pos[2] = player_coordinate(x - VIEW_X + HITBOX_W);
	data->room->p_pos[3] = player_coordinate(y - VIEW_Y + HITBOX_H);
	player_move(data);
	player_actions(data);
}
