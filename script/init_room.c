/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:56:20 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/30 17:57:09 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	room_render(t_mlx_data *data)
{
	static int	ppos[3];
	static int	init = 0;

	if (data->map->isvalid == 0)
		return (0);
	if (init == 0 || (ppos[0] != data->map->player_pos[0] - 1
			|| ppos[1] != data->map->player_pos[1] - 1))
	{
		init = 1;
		ppos[0] = data->map->player_pos[0] - 1;
		ppos[1] = data->map->player_pos[1] - 1;
		data->room = room_clear(data->room);
		data->room = room_paste(data->room, data->map, ppos);
		ft_roomprint(data->room);
	}
	map_decor(data);
	return (1);
}

t_room	*room_clear(t_room *room)
{
	int	x;
	int	y;

	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			room->map[y][x] = '.';
			x++;
		}
		room->map[y][x] = '\n';
		x++;
		room->map[y][x] = '\0';
		y++;
	}
	room->map[y][x] = '\0';
	return (room);
}

t_room	*room_paste(t_room *room, t_map *map, int *ppos)
{
	int	x;
	int	y;

	y = 0;
	while (y < 5 && y < map->size_y)
	{
		x = 0;
		while (x < 5)
		{
			if (x < map->size_x)
				room->map[y][x] = map->map[y
					+ (4 * ppos[1])][x + (4 * ppos[0])];
			else
				room->map[y][x] = '.';
			x++;
		}
		room->map[y][x] = '\n';
		x++;
		room->map[y][x] = '\0';
		y++;
	}
	return (room);
}

void	map_decor(t_mlx_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y <= 6)
	{
		x = 0;
		while (x <= 6)
		{
			map_tilepos(data, x + 1, y + 1, data->room->map[y][x]);
			x++;
		}
		y++;
	}
}
