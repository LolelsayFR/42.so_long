/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:16:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/16 19:23:32 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_init(t_mlx_data *data)
{
	char	*str;
	int		fd;

	ft_printf(YEL"[MAP INIT]\n"RES);
	data->map->end = 0;
	data->map->player = 0;
	fd = open(data->map->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(RED"[ERROR]\nBad map paths.\n"RES);
		return (RETURN_ERROR);
	}
	data->map->temp_map = NULL;
	while (1)
	{
		str = get_next_line(fd);
		ft_lstadd_back(&data->map->temp_map, ft_lstnew(str));
		if (!str)
			break ;
	}
	close(fd);
	free(str);
	return (map_paste(data));
}

int	map_paste(t_mlx_data *data)
{
	int		i;

	i = ft_lstsize(data->map->temp_map);
	data->map->map = ft_calloc((i + 1), sizeof(char *));
	if (!data->map->map)
		return (RETURN_ERROR);
	data->map->visited_map = ft_calloc((i + 1), sizeof(char *));
	if (!data->map->visited_map)
		return (RETURN_ERROR);
	if (!map_paste_dup(data))
		return (RETURN_ERROR);
	return (map_paste2(data, 0, 0));
}

int	map_paste2(t_mlx_data *data, int x, int y)
{
	y = 0;
	while (data->map->map[y] != NULL)
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == M_PLAYER && data->map->player == 0)
			{
				data->player->pos_x = ((x % 4) * TILE_SIZE * 3) + VIEW_X
					- (TILE_SIZE / 2) - (HITBOX_W / 2);
				data->player->pos_y = ((y % 4) * TILE_SIZE * 3) + VIEW_Y
					- (TILE_SIZE / 2) - (HITBOX_H / 2);
				data->map->player_pos[0] = x / 4 + 1;
				data->map->player_pos[1] = y / 4 + 1;
			}
			map_data_init(data, data->map->map[y][x], x, y);
			x++;
		}
		y++;
	}
	data->enemy = ft_calloc(data->map->enemy + 1, sizeof(t_enemy *));
	return (map_check(data));
}

int	map_check(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i] != NULL)
	{
		ft_printf("%s", data->map->map[i]);
		if (ft_strlen(data->map->map[i]) != ft_strlen(data->map->map[0]))
			return (ft_printf(YEL"Map not rectangular...\n"RES), 0);
		j = 0;
		while (data->map->map[i][j])
		{
			if (!ft_strchr(MAP_SET, data->map->map[i][j])
				&& j < data->map->size_x)
				return (ft_printf(YEL"Char set invalid !\n"RES), 0);
			if ((((i == 0 || i == data->map->size_y) && j < data->map->size_x)
					|| j == 0 || j == data->map->size_x - 1)
				&& (data->map->map[i][j] != M_WALL))
				return (ft_printf(YEL"Map not closed by wall..\n"RES), 0);
			enemy_create(data, data->map->map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (map_check2(data));
}

int	map_check2(t_mlx_data *data)
{
	int		new_size_x;
	int		new_size_y;

	if (data->map->size_x % 4 != 1 || data->map->size_y % 4 != 1)
		ft_printf("[WARNING]\nMap too smol, 5x5 map minimum\n");
	if (data->map->player != 1)
		return (ft_printf(YEL"Invalid player spawn count.\n"RES), 0);
	if (data->map->obj < 1)
		return (ft_printf(YEL"Invalid colectible count.\n"RES), 0);
	if (data->map->end != 1)
		return (ft_printf(YEL"Invalid end count.\n"RES), 0);
	if (data->map->size_x % 4 == 1)
		new_size_x = data->map->size_x;
	else
		new_size_x = data->map->size_x + (4 - (data->map->size_x % 4) + 1);
	if (data->map->size_y % 4 == 1)
		new_size_y = data->map->size_y;
	else
		new_size_y = data->map->size_y + (4 - (data->map->size_y % 4) + 1);
	if (check_rectangular(data->map->map)
		&& (new_size_x != data->map->size_x || new_size_y != data->map->size_y))
		expand_map(data, new_size_x, new_size_y);
	data->floodfill->map = tabdup(data->map->map);
	floodfill(data, data->player->spawn[1], data->player->spawn[0]);
	return (1);
}
