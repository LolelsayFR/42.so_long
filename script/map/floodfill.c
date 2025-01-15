/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 06:02:46 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/15 08:16:23 by emaillet         ###   ########.fr       */
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
	int		size_y;

	i = 0;
	size_y = 0;
	while (tab[size_y] != NULL)
		size_y++;
	while (i < size_y)
	{
		ft_printf("%s", tab[i]);
		i++;
	}
}

int floodfill_collect(t_mlx_data *data, int x, int y)
{
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
    data->floodfill->map[y][x] = M_FLOOD;
    floodfill_collect(data, x + 1, y);
    floodfill_collect(data, x - 1, y);
    floodfill_collect(data, x, y + 1);
    floodfill_collect(data, x, y - 1);
    return (1);
}

int floodfill_reach(t_mlx_data *data, int x, int y)
{
	ft_printf("\n\nSecond Flood = x %i y %i \n", x, y);
    maprint(data->floodfill->map);
    if (x < 0 || x >= data->map->size_x || y < 0 || y >= data->map->size_y)
        return (0);
    if (data->floodfill->map[y][x] == M_WALL || data->floodfill->map[y][x] == M_FLOOD2 ||
        (data->floodfill->map[y][x] == M_DOOR_OBJ_C && data->floodfill->obj < data->map->obj))
        return (0);
    if (data->floodfill->map[y][x] == M_FINISH && data->floodfill->obj == data->map->obj)
        return (1);
    data->floodfill->map[y][x] = M_FLOOD2;
    if (floodfill_reach(data, x + 1, y)
        || floodfill_reach(data, x - 1, y)
        || floodfill_reach(data, x, y + 1)
        || floodfill_reach(data, x, y - 1))
        return (1);

    return (0);
}

int floodfill(t_mlx_data *data, int x, int y)
{
    floodfill_collect(data, x, y);
	if (!floodfill_reach(data, x, y))
	{
		if (data->floodfill->obj != data->map->obj)
			ft_printf(YEL"[WARNING]\nFirst floodfill cant get all objectives...\n"RES);
		ft_printf(YEL"[WARNING]\nSecond floodfill cant reach the end of map...\n"RES);
		return (0);
	}
    return (1);
}
