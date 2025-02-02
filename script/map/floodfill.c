/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 06:02:46 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/18 15:01:01 by emaillet         ###   ########.fr       */
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
	int			i;
	int			j;
	static int	call = 0;

	if (!DEBUG)
		return ((void)ft_printf("Floodfill step %i\n", call++));
	i = 0;
	while (tab[i] != NULL)
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
	if (DEBUG)
		ft_printf("\n\nFirst Flood = x %i y %i \n", x, y);
	maprint(data->floodfill->map);
	if (x < 0 || x >= data->map->size_x || y < 0 || y >= data->map->size_y)
		return (0);
	if (data->floodfill->map[y][x] == M_WALL
		|| data->floodfill->map[y][x] == M_FLOOD
		|| data->floodfill->map[y][x] == M_DOOR_OBJ_C)
		return (0);
	if (data->floodfill->map[y][x] == M_CH_OBJ_C)
		data->floodfill->obj++;
	if (x % 4 == 0 && y % 4 == 0
		&& ft_strchr(MAP_CORN_ERROR, data->floodfill->map[y][x]))
	{
		sl_logs(data->logs->floodfill, YEL
			"Map has a corner error... Aborting"RES, x, y);
		return (data->floodfill->obj = INT_MIN, 0);
	}
	data->floodfill->map[y][x] = M_FLOOD;
	floodfill_collect(data, x + 1, y);
	floodfill_collect(data, x - 1, y);
	floodfill_collect(data, x, y + 1);
	floodfill_collect(data, x, y - 1);
	return (1);
}

int	floodfill_reach(t_mlx_data *data, int x, int y)
{
	if (DEBUG)
		ft_printf("\n\nSecond Flood = x %i y %i \n", x, y);
	maprint(data->floodfill->map);
	if (x < 0 || x >= data->map->size_x || y < 0 || y >= data->map->size_y)
		return (0);
	if (data->floodfill->map[y][x] == M_WALL
		|| data->floodfill->map[y][x] == M_FLOOD2)
		return (0);
	if ((x % 4 == 0 || y % 4 == 0) && data->floodfill->map[y][x] == M_PLAYER)
	{
		sl_logs(data->logs->floodfill, YEL
			"Player Spawn in wall... Aborting"RES);
		return (0);
	}
	if (data->floodfill->map[y][x] == M_FINISH)
		return (1);
	data->floodfill->map[y][x] = M_FLOOD2;
	if (floodfill_reach(data, x + 1, y)
		|| floodfill_reach(data, x - 1, y)
		|| floodfill_reach(data, x, y + 1)
		|| floodfill_reach(data, x, y - 1))
		return (1);
	return (0);
}

int	floodfill(t_mlx_data *data, int x, int y)
{
	static int	i = 0;

	sl_logs(data->logs->map, "\n\e[1m~Base map before floodfill"RES);
	sl_maplogs(data, data->floodfill->map);
	floodfill_collect(data, x, y);
	sl_logs(data->logs->map, "\n\e[1m~Map after first floodfill"RES);
	sl_maplogs(data, data->floodfill->map);
	if (data->floodfill->obj != data->map->obj)
	{
		sl_logs(data->logs->floodfill, YEL
			"First floodfill fail.. Aborting"RES);
		return (0);
	}
	while (data->floodfill->map[i])
		free(data->floodfill->map[i++]);
	free(data->floodfill->map);
	data->floodfill->map = tabdup(data->map->map);
	if (!floodfill_reach(data, x, y))
	{
		sl_logs(data->logs->floodfill, YEL
			"Second floodfill cant reach the end of map..."RES);
		return (0);
	}
	sl_logs(data->logs->map, "\n\e[1m~Map after second floodfill"RES);
	return (sl_maplogs(data, data->floodfill->map), 1);
}
