/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:04:10 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/16 19:01:49 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	expand_init(char ***map, char ***visited, int size_y)
{
	*map = ft_calloc((size_y + 1), sizeof(char *));
	if (!*map)
		return (RETURN_ERROR);
	*visited = ft_calloc((size_y + 1), sizeof(char *));
	if (!*visited)
		return (RETURN_ERROR);
	return (RETURN_SUCCESS);
}

void	ex_fill_line(t_mlx_data *data, char **map, char **visited, int pos[2])
{
	int	y;

	y = 0;
	while (y < pos[1])
	{
		if (pos[0] < data->map->size_y && y < data->map->size_x)
		{
			map[pos[0]][y] = data->map->map[pos[0]][y];
			visited[pos[0]][y] = data->map->visited_map[pos[0]][y];
		}
		else
		{
			map[pos[0]][y] = M_WALL;
			visited[pos[0]][y] = M_NOT_VISITED;
		}
		y++;
	}
	if (y <= pos[1])
	{
		map[pos[0]][y] = '\n';
		visited[pos[0]][y] = '\n';
	}
}

void	expand_fill(t_mlx_data *data, char **map, char **visited, int sizes[2])
{
	int	x;
	int	pos[2];

	x = 0;
	while (x < sizes[1])
	{
		map[x] = ft_calloc((sizes[0] + 2), sizeof(char));
		visited[x] = ft_calloc((sizes[0] + 2), sizeof(char));
		if (!map[x] || !visited[x])
			return ;
		pos[0] = x;
		pos[1] = sizes[0];
		ex_fill_line(data, map, visited, pos);
		x++;
	}
}

void	expand_free_old(t_mlx_data *data)
{
	int	x;

	x = 0;
	while (x <= data->map->size_y)
	{
		free(data->map->map[x]);
		free(data->map->visited_map[x]);
		x++;
	}
	free(data->map->map);
	free(data->map->visited_map);
}

int	expand_map(t_mlx_data *data, int new_size_x, int new_size_y)
{
	char	**new_map;
	char	**new_visited_map;
	int		sizes[2];

	if (expand_init(&new_map, &new_visited_map, new_size_y) == RETURN_ERROR)
		return (RETURN_ERROR);
	sizes[0] = new_size_x;
	sizes[1] = new_size_y;
	expand_fill(data, new_map, new_visited_map, sizes);
	new_map[new_size_y] = NULL;
	new_visited_map[new_size_y] = NULL;
	expand_free_old(data);
	data->map->map = new_map;
	data->map->visited_map = new_visited_map;
	data->map->size_x = new_size_x;
	data->map->size_y = new_size_y;
	return (1);
}
