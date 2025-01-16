/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 06:02:46 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/16 19:00:15 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**tabdup(char **map)
{
	int		i;
	int		size_y;
	char	**new_map;

	i = 0;
	size_y = 0;
	while (map[size_y] != NULL)
		size_y++;
	new_map = ft_calloc((size_y + 1), sizeof(char *));
	while (i < size_y)
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[size_y] = NULL;
	return (new_map);
}

void	maprint(char **tab)
{
	int		i;
	int		j;
	int		size_y;

	i = 0;
	size_y = 0;
	while (tab[size_y] != NULL)
		size_y++;
	while (i < size_y)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == M_WALL)
				ft_printf(RED"%c"RES, tab[i][j]);
			else if (tab[i][j] == M_FLOOD)
				ft_printf(YEL"%c"RES, tab[i][j]);
			else if (tab[i][j] == M_FLOOD2)
				ft_printf(GRN"%c"RES, tab[i][j]);
			else
				ft_printf("%c", tab[i][j]);
			j++;
		}
		i++;
	}
}

int	floodfill_collect(t_mlx_data *data, int x, int y)
{
	ft_printf("\n\nFirst Flood = x %i y %i \n", x, y);
	maprint(data->floodfill->map);
	if (x < 0 || x >= data->map->size_x || y < 0 || y >= data->map->size_y)
		return (0);
	if (data->floodfill->map[y][x] == M_WALL
		|| data->floodfill->map[y][x] == M_FLOOD
		|| data->floodfill->map[y][x] == M_DOOR_OBJ_C
		|| data->floodfill->map[y][x] == M_FINISH)
		return (0);
	if (data->floodfill->map[y][x] == M_CH_OBJ_C)
		data->floodfill->obj++;
	data->floodfill->map[y][x] = M_FLOOD;
	floodfill_collect(data, x + 1, y);
	floodfill_collect(data, x - 1, y);
	floodfill_collect(data, x, y + 1);
	floodfill_collect(data, x, y - 1);
	return (1);
}

int	floodfill_reach(t_mlx_data *data, int x, int y)
{
	ft_printf("\n\nSecond Flood = x %i y %i \n", x, y);
	maprint(data->floodfill->map);
	if (x < 0 || x >= data->map->size_x || y < 0 || y >= data->map->size_y)
		return (0);
	if (data->floodfill->map[y][x] == M_WALL
		|| data->floodfill->map[y][x] == M_FLOOD2)
		return (0);
	if (data->floodfill->map[y][x] == M_FINISH)
		return (data->floodfill->isvalid = 1, 1);
	data->floodfill->map[y][x] = M_FLOOD2;
	if (floodfill_reach(data, x + 1, y)
		|| floodfill_reach(data, x - 1, y)
		|| floodfill_reach(data, x, y + 1)
		|| floodfill_reach(data, x, y - 1))
		return (1);
	return (data->floodfill->isvalid = 0, 0);
}

int	floodfill(t_mlx_data *data, int x, int y)
{
	floodfill_collect(data, x, y);
	if (data->floodfill->obj != data->map->obj)
	{
		ft_printf(YEL"[WARNING]\n"
			"First floodfill cant get all objectives... Aborting\n"RES);
		return (0);
	}
	if (!floodfill_reach(data, x, y))
	{
		ft_printf(YEL
			"[WARNING]\nSecond floodfill cant reach the end of map...\n"RES);
		return (0);
	}
	return (1);
}
