/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:02:43 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/07 08:34:53 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	mlx_clock(t_mlx_data *data)
{
	usleep(1000000 / 30);
	mlx_actions(data);
	mlx_render(data);
	return (1);
}

void	mlx_render(t_mlx_data *data)
{
	map_decor(data, data->map->player_pos[0], data->map->player_pos[1]);
	mlx_put_player(data, data->player->pos_x, data->player->pos_y);
}

void	mlx_actions(t_mlx_data *data)
{
	player_move(data);
}
