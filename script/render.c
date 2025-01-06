/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:02:43 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/06 21:23:02 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_clock(t_mlx_data *data)
{
	static int	i = 0;

	if (data->map->isvalid == 0)
		return (ft_printf(RED"[MAP ERROR]\nRead above.\n"RES), mlx_close(data));
	usleep(1000000 / FPS);
	i++;
	if (i == FPS)
	{
		i = 0;
		mlx_timer(data);
	}
	mlx_render(data);
	mlx_actions(data, data->player->pos_x, data->player->pos_y);
	return (1);
}

void	mlx_render(t_mlx_data *data)
{
	room_render(data);
	mlx_put_player(data, data->player->pos_x, data->player->pos_y);
	mlx_hud_render(data);
}

void	mlx_actions(t_mlx_data *data, int x, int y)
{
	action_cooldown(data);
	data->room->p_pos[0] = player_coordinate(x - VIEW_X);
	data->room->p_pos[1] = player_coordinate(y - VIEW_Y);
	data->room->p_pos[2] = player_coordinate(x - VIEW_X + HITBOX_W);
	data->room->p_pos[3] = player_coordinate(y - VIEW_Y + HITBOX_H);
	player_move(data);
	player_actions(data);
}

void	mlx_hud_render(t_mlx_data *data)
{
	char	*temp[3];

	temp[0] = ft_itoa(data->player->player_step);
	mlx_put_hud_bg(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		650, 400, 0xFFFFFFFF, temp[0]);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		650, 458, 0xFFFFFFFF, data->timer);
	free(temp[0]);
	temp[0] = ft_itoa(data->player->obj);
	temp[1] = ft_itoa(data->map->obj);
	temp[2] = ft_strjoin(temp[0], "/");
	data->obj = ft_strjoin(temp[2], temp[1]);
	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		807, 458, 0xFFFFFFFF, data->obj);
	free(data->obj);
}
