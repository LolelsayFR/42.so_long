/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:16:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/03 18:38:14 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_init(t_mlx_data *data)
{
	char	*str;
	int		fd;

	ft_printf(YEL"[MAP INIT]\n"RES);
	fd = open(data->map->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(RED"[ERROR] Bad map paths.\n"RES);
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
	t_list	*temp;

	i = ft_lstsize(data->map->temp_map);
	data->map->map = malloc((i + 1) * sizeof(char *));
	data->map->visited_map = malloc((i + 1) * sizeof(char *));
	i = 0;
	temp = data->map->temp_map;
	while (temp->content != NULL)
	{
		data->map->map[i] = ft_strdup(temp->content);
		data->map->visited_map[i] = ft_strdup(temp->content);
		ft_memset(data->map->visited_map[i], '*', ft_strlen(temp->content) - 1);
		i++;
		temp = temp->next;
	}
	data->map->visited_map[i] = NULL;
	data->map->map[i] = NULL;
	data->map->size_x = ft_strlen(data->map->map[0]) - 1;
	data->map->size_y = i - 2;
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
			if (data->map->map[y][x] == '@')
			{
				data->player->pos_x = ((x % 4) * TILE_SIZE * 3) + VIEW_X
					- (TILE_SIZE / 2) - (HITBOX_W / 2);
				data->player->pos_y = ((y % 4) * TILE_SIZE * 3) + VIEW_Y
					- (TILE_SIZE / 2) - (HITBOX_H / 2);
				data->map->player_pos[0] = x / 4 + 1;
				data->map->player_pos[1] = y / 4 + 1;
			}
			x++;
		}
		y++;
	}
	if (map_check(data))
		return (1);
	else
		return (RETURN_ERROR);
}

int	map_check(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i] != NULL)
	{
		ft_printf("%s", data->map->map[i]);
		i++;
	}
	return (1);
}

void	visited_paste(t_map *map, int *ppos)
{
	int	x;
	int	y;

	y = 0;
	while (y < 5 && y < map->size_y)
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
