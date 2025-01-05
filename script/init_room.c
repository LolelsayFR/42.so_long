/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:56:20 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/05 02:57:14 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	room_render(t_mlx_data *data)
{
	if (data->map->isvalid == 0)
		return (0);
	if (data->room->r_pos[0] != data->map->player_pos[0] - 1
		|| data->room->r_pos[1] != data->map->player_pos[1] - 1)
	{
		data->room->r_pos[0] = data->map->player_pos[0] - 1;
		data->room->r_pos[1] = data->map->player_pos[1] - 1;
		visited_paste(data->map, data->room->r_pos);
		data->room = room_clear(data->room);
		data->room = room_paste(data->room, data->map, data->room->r_pos);
		room_print(data->room);
		map_print(data->map->visited_map);
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
			room->map[y][x] = M_WALL;
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
				room->map[y][x] = map->visited_map[y + (4 * ppos[1])]
				[x + (4 * ppos[0])];
			else
				room->map[y][x] = M_WALL;
			if (room->map[y][x] == M_PLAYER)
				room->map[y][x] = M_FLOOR;
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
