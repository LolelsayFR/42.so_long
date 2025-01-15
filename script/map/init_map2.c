/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:59:36 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/15 06:46:26 by emaillet         ###   ########.fr       */
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
	{
		data->map->player++;
		data->player->spawn[0] = y;
		data->player->spawn[1] = x;
	}
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

int	map_paste_dup(t_mlx_data *data)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = data->map->temp_map;
	while (temp != NULL)
	{
		if (temp->content != NULL)
		{
			data->map->map[i] = ft_strdup(temp->content);
			data->map->visited_map[i] = ft_strdup(temp->content);
			if (!data->map->map[i] || !data->map->visited_map[i])
				return (RETURN_ERROR);
			ft_memset(data->map->visited_map[i], M_NOT_VISITED,
				ft_strlen(temp->content) - 1);
		}
		i++;
		temp = temp->next;
	}
	data->map->visited_map[i] = NULL;
	data->map->map[i] = NULL;
	data->map->size_x = ft_strlen(data->map->map[0]) - 1;
	data->map->size_y = i - 1;
	return (i);
}
