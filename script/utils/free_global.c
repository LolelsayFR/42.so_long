/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:55:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/17 22:09:17 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mlx_close(t_mlx_data *data)
{
	sl_logs_free(data);
	sprite_clear_minimap(data);
	enemy_free(data);
	free(data->timer);
	free(data->control);
	sprite_clear_player(data);
	free(data->player);
	sprite_clear_tilemap1(data);
	free(data->img->tilemap);
	map_free(data);
	mlx_destroy_image(data->mlx_ptr, data->img->hud_bg);
	mlx_destroy_image(data->mlx_ptr, data->img->bg);
	free(data->room);
	free(data->map);
	sprite_clear_ui(data);
	free(data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(data->state);
}

int	map_free(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i] && data->map->visited_map[i])
	{
		free(data->map->map[i]);
		free(data->map->visited_map[i]);
		if (data->floodfill->map)
			free(data->floodfill->map[i]);
		i++;
	}
	free(data->map->map);
	free(data->map->visited_map);
	if (data->floodfill->map)
		free(data->floodfill->map);
	free(data->floodfill);
	ft_lstclear(&data->map->temp_map, free);
	return (1);
}
