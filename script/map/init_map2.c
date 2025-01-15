/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:59:36 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 09:18:56 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_data_init(t_mlx_data *data, char c, int x, int y)
{
	if (c == M_CH_OBJ_C)
		data->map->obj++;
	else if (c == M_CH_HP_C)
		data->map->potion++;
	else if (c == M_ENEMY || c == M_SPIKE)
		data->map->enemy++;
	else if (c == M_FINISH)
	{
		data->map->end_pos[0] = x;
		data->map->end_pos[1] = y;
		data->map->end++;
	}
	else if (c == M_PLAYER)
		data->map->player++;
}

void	visited_paste(t_map *map, int *ppos)
{
	int	x;
	int	y;

	y = 0;
	while (y < 5 && y <= map->size_y)
	{
		x = 0;
		while (x < 5)
		{
			if (map->visited_map[y + (4 * ppos[1])]
				[x + (4 * ppos[0])] == M_NOT_VISITED)
				map->visited_map[y + (4 * ppos[1])][x + (4 * ppos[0])]
					= map->map[y + (4 * ppos[1])][x + (4 * ppos[0])];
			x++;
		}
		y++;
	}
}
