/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:16:45 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/07 11:10:11 by emaillet         ###   ########.fr       */
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
		mlx_close(data);
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
	i = 0;
	temp = data->map->temp_map;
	while (temp->content != NULL)
	{
		data->map->map[i] = ft_strdup(temp->content);
		i++;
		temp = temp->next;
	}
	data->map->map[i] = NULL;
	data->map->size_x = ft_strlen(data->map->map[0]);
	data->map->size_y = i;
	ft_printf("x = %i \ny = %i\n", data->map->size_x, data->map->size_y);
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

void	map_decor(t_mlx_data *data, int or_x, int or_y)
{
	int	x;
	int	y;

	y = 0;
	or_y--;
	or_x--;
	or_y *= 4;
	or_x *= 4;
	while (data->map->map[y + or_y] != NULL && y <= 6)
	{
		x = 0;
		while (data->map->map[y + or_y][x + or_x] && x <= 6)
		{
			map_tilepos(data, x + 1, y + 1,
				data->map->map[y + or_y][x + or_x]);
			x++;
		}
		y++;
	}
}

int	map_free(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i] != NULL)
	{
		free(data->map->map[i]);
		i++;
	}
	free(data->map->map);
	ft_lstclear(&data->map->temp_map, free);
	free(data->map);
	return (1);
}
