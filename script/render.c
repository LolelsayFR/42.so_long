/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:02:43 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/30 04:03:03 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_render(t_mlx_data *data)
{
	player_move(data);
	if (data->updated)
	{
		mlx_put_background(data);
		mlx_put_player(data, data->player->pos_x, data->player->pos_y);
	}
	data->updated = 0;
	return (0);
}
