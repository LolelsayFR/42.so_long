/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:51:19 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/30 19:20:41 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_hitbox(t_mlx_data *data, int x, int y)
{
	int	xy[6];

	xy[0] = player_coordinate(x - VIEW_X);
	xy[1] = player_coordinate(y - VIEW_Y);
	xy[2] = player_coordinate(x - VIEW_X + HITBOX_W);
	xy[3] = player_coordinate(y - VIEW_Y + HITBOX_H);
	xy[4] = player_coordinate(x - VIEW_X + HITBOX_W / 2);
	xy[5] = player_coordinate(y - VIEW_Y + HITBOX_H / 2);
	if (player_colider(data, xy))
		return (0);
	else if (data->room->map[(xy[5] - 1)][(xy[4] - 1)] == ':')
		return (2);
	else if (data->room->map[(xy[5] - 1)][(xy[4] - 1)] == '~')
		return (2);
	return (1);
}

int	player_colider(t_mlx_data *data, int *xy)
{
	char	*set;

	set = "WDE";
	if (ft_strchr(set, data->room->map[(xy[1] - 1)][(xy[0] - 1)]))
		return (1);
	else if (ft_strchr(set, data->room->map[(xy[3] - 1)][(xy[2] - 1)]))
		return (1);
	return (0);
}
