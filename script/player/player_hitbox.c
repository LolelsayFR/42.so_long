/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hitbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:51:19 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 08:52:10 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_hitbox(t_mlx_data *data, int x, int y)
{
	int	xy[4];

	xy[0] = player_coordinate(x - VIEW_X);
	xy[1] = player_coordinate(y - VIEW_Y);
	xy[2] = player_coordinate(x - VIEW_X + HITBOX_W);
	xy[3] = player_coordinate(x - VIEW_X + HITBOX_H);
	if (player_colider(data, x, y))
		return (0);
	if (player_hitbox_door(data, x, y, xy))
		return (0);
	return (1);
}

int	player_hitbox_door(t_mlx_data *data, int x, int y, int *xy)
{
	char	*set;

	set = MAP_OPEN_DOOR;
	if (door_check(x - VIEW_X + HITBOX_W / 2, y - VIEW_X + HITBOX_H / 2))
	{
		if (ft_strchr(set, data->room->map[(xy[1] - 1)][(xy[0] - 1)]))
			return (1);
		else if (ft_strchr(set, data->room->map[(xy[3] - 1)][(xy[2] - 1)]))
			return (1);
	}
	return (0);
}

int	player_colider(t_mlx_data *data, int x, int y)
{
	int		hit[5][3];
	char	*set;

	hit[0][0] = player_coordinate(x - VIEW_X + HITBOX_W);
	hit[0][1] = player_coordinate(y - VIEW_Y + HITBOX_H);
	hit[1][0] = player_coordinate(x - VIEW_X + HITBOX_W);
	hit[1][1] = player_coordinate(y - VIEW_Y);
	hit[2][0] = player_coordinate(x - VIEW_X);
	hit[2][1] = player_coordinate(y - VIEW_Y + HITBOX_H);
	hit[3][0] = player_coordinate(x - VIEW_X);
	hit[3][1] = player_coordinate(y - VIEW_Y);
	set = MAP_COLIDE;
	if (ft_strchr(set, data->room->map[(hit[1][1] - 1)][(hit[1][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[2][1] - 1)][(hit[2][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[3][1] - 1)][(hit[3][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[0][1] - 1)][(hit[0][0] - 1)]))
		return (1);
	return (0);
}
