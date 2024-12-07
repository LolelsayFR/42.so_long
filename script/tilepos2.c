/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilepos2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 08:23:53 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/07 12:39:29 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_wallpos2(t_mlx_data *data, int x, int y, int *xy)
{
	if (x == 1 && y == 1)
		mlx_put_tiles(data, data->img->tilemap->wall[6], x - xy[0], y - xy[1]);
	else if (x == 1 && y == 13)
		mlx_put_tiles(data, data->img->tilemap->wall[0], x - xy[0], y - xy[1]);
	else if (x == 13 && y == 1)
		mlx_put_tiles(data, data->img->tilemap->wall[3], x - xy[0], y - xy[1]);
	else if (x == 13 && y == 13)
		mlx_put_tiles(data, data->img->tilemap->wall[4], x - xy[0], y - xy[1]);
	else if (x == 13)
		mlx_put_tiles(data, data->img->tilemap->wall[2], x - xy[0], y - xy[1]);
	else if (y == 13)
		mlx_put_tiles(data, data->img->tilemap->wall[1], x - xy[0], y - xy[1]);
	else if (x == 1)
		mlx_put_tiles(data, data->img->tilemap->wall[5], x - xy[0], y - xy[1]);
	else if (y == 1)
		mlx_put_tiles(data, data->img->tilemap->wall[7], x - xy[0], y - xy[1]);
	else
		mlx_put_tiles(data, data->img->tilemap->error, x - xy[0], y - xy[1]);
}

void	map_floorpos2(t_mlx_data *data, int x, int y)
{
	if (x == 2 && y == 2)
		mlx_put_tiles(data, data->img->tilemap->floor[3], x, y);
	else if (x == 2 && y == 10)
		mlx_put_tiles(data, data->img->tilemap->floor[8], x, y);
	else if (x == 10 && y == 2)
		mlx_put_tiles(data, data->img->tilemap->floor[7], x, y);
	else if (x == 10 && y == 10)
		mlx_put_tiles(data, data->img->tilemap->floor[5], x, y);
	else if (x == 10)
		mlx_put_tiles(data, data->img->tilemap->floor[6], x, y);
	else if (y == 10)
		mlx_put_tiles(data, data->img->tilemap->floor[1], x, y);
	else if (x == 2)
		mlx_put_tiles(data, data->img->tilemap->floor[2], x, y);
	else if (y == 2)
		mlx_put_tiles(data, data->img->tilemap->floor[4], x, y);
	else
		mlx_put_tiles(data, data->img->tilemap->floor[0], x, y);
}

void	map_chestpos2(t_mlx_data *data, int x, int y, int *xy)
{
	if (xy[3] == ':' && xy[1] == 1 && xy[0] == 1)
		mlx_put_tiles(data, data->img->tilemap->chest[0], x, y);
	else if (xy[3] == '~' && xy[1] == 1 && xy[0] == 1)
		mlx_put_tiles(data, data->img->tilemap->red_chest[0], x, y);
	else if (xy[3] == ';' && xy[1] == 1 && xy[0] == 1)
		mlx_put_tiles(data, data->img->tilemap->chest[1], x, y);
	else if (xy[3] == '-' && xy[1] == 1 && xy[0] == 1)
		mlx_put_tiles(data, data->img->tilemap->red_chest[1], x, y);
	else
		map_floorpos2(data, x, y);
}

void	map_doorpos2(t_mlx_data *data, int x, int y, int *xy)
{
	if (xy[1] == 0 && x == 11)
		mlx_put_tiles(data, data->img->tilemap->door_right[2], x, y);
	else if (xy[1] == 1 && x == 11)
		mlx_put_tiles(data, data->img->tilemap->door_right[xy[4]], x, y);
	else if (xy[1] == 2 && x == 11)
		mlx_put_tiles(data, data->img->tilemap->door_right[0], x, y);
	else if (xy[0] == 0 && y == 11)
		mlx_put_tiles(data, data->img->tilemap->door_down[2], x, y);
	else if (xy[0] == 1 && y == 11)
		mlx_put_tiles(data, data->img->tilemap->door_down[xy[4]], x, y);
	else if (xy[0] == 2 && y == 11)
		mlx_put_tiles(data, data->img->tilemap->door_down[0], x, y);
	else if (xy[1] == 0 && x == 1)
		mlx_put_tiles(data, data->img->tilemap->door_left[2], x, y);
	else if (xy[1] == 1 && x == 1)
		mlx_put_tiles(data, data->img->tilemap->door_left[xy[4]], x, y);
	else if (xy[1] == 2 && x == 1)
		mlx_put_tiles(data, data->img->tilemap->door_left[0], x, y);
	else if (xy[0] == 0 && y == 1)
		mlx_put_tiles(data, data->img->tilemap->door_up[2], x, y);
	else if (xy[0] == 1 && y == 1)
		mlx_put_tiles(data, data->img->tilemap->door_up[xy[4]], x, y);
	else if (xy[0] == 2 && y == 1)
		mlx_put_tiles(data, data->img->tilemap->door_up[0], x, y);
}

void	map_doorpos3(t_mlx_data *data, int x, int y, int *xy)
{
	if (xy[1] == 0 && x == 11)
		mlx_put_tiles(data, data->img->tilemap->end_right[2], x, y);
	else if (xy[1] == 1 && x == 11)
		mlx_put_tiles(data, data->img->tilemap->end_right[xy[4]], x, y);
	else if (xy[1] == 2 && x == 11)
		mlx_put_tiles(data, data->img->tilemap->end_right[0], x, y);
	else if (xy[0] == 0 && y == 11)
		mlx_put_tiles(data, data->img->tilemap->end_down[2], x, y);
	else if (xy[0] == 1 && y == 11)
		mlx_put_tiles(data, data->img->tilemap->end_down[xy[4]], x, y);
	else if (xy[0] == 2 && y == 11)
		mlx_put_tiles(data, data->img->tilemap->end_down[0], x, y);
	else if (xy[1] == 0 && x == 1)
		mlx_put_tiles(data, data->img->tilemap->end_left[2], x, y);
	else if (xy[1] == 1 && x == 1)
		mlx_put_tiles(data, data->img->tilemap->end_left[xy[4]], x, y);
	else if (xy[1] == 2 && x == 1)
		mlx_put_tiles(data, data->img->tilemap->end_left[0], x, y);
	else if (xy[0] == 0 && y == 1)
		mlx_put_tiles(data, data->img->tilemap->end_up[2], x, y);
	else if (xy[0] == 1 && y == 1)
		mlx_put_tiles(data, data->img->tilemap->end_up[xy[4]], x, y);
	else if (xy[0] == 2 && y == 1)
		mlx_put_tiles(data, data->img->tilemap->end_up[0], x, y);
}
