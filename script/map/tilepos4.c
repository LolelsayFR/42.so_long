/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilepos4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:31:56 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/15 05:45:11 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	_door_corners(t_mlx_data *data, int base[2], int pos[2])
{
	if (pos[0] == 0 && pos[1] == 2)
		mlx_put_tiles(data, data->img->tilemap->wall[0],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (pos[0] == 2 && pos[1] == 2)
		mlx_put_tiles(data, data->img->tilemap->wall[4],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (pos[0] == 0 && pos[1] == 0)
		mlx_put_tiles(data, data->img->tilemap->wall[6],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (pos[0] == 2 && pos[1] == 0)
		mlx_put_tiles(data, data->img->tilemap->wall[3],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
}

static void	_door_center(t_mlx_data *data, int base[2], int pos[2], int isopen)
{
	if (isopen && pos[0] == 1 && pos[1] == 1)
		mlx_put_tiles(data, data->img->tilemap->floor[0],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (!isopen && pos[0] == 1 && pos[1] == 1)
		mlx_put_tiles(data, data->img->tilemap->voids,
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
}

static void	_door_obj(t_mlx_data *data, int base[2], int pos[2], int isopen)
{
	if (pos[0] == 1 && pos[1] == 0)
		mlx_put_tiles(data, data->img->tilemap->end_up[3 - isopen],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (pos[0] == 2 && pos[1] == 1)
		mlx_put_tiles(data, data->img->tilemap->end_right[3 - isopen],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (pos[0] == 1 && pos[1] == 2)
		mlx_put_tiles(data, data->img->tilemap->end_down[3 - isopen],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (pos[0] == 0 && pos[1] == 1)
		mlx_put_tiles(data, data->img->tilemap->end_left[3 - isopen],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
}

static void	_door_normal(t_mlx_data *data, int base[2], int pos[2], int isopen)
{
	if (pos[0] == 1 && pos[1] == 0)
		mlx_put_tiles(data, data->img->tilemap->door_up[3 - isopen],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (pos[0] == 2 && pos[1] == 1)
		mlx_put_tiles(data, data->img->tilemap->door_right[3 - isopen],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (pos[0] == 1 && pos[1] == 2)
		mlx_put_tiles(data, data->img->tilemap->door_down[3 - isopen],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
	else if (pos[0] == 0 && pos[1] == 1)
		mlx_put_tiles(data, data->img->tilemap->door_left[3 - isopen],
			base[0] + pos[0] - 2, base[1] + pos[1] - 2);
}

void	map_doorpos_middle(t_mlx_data *data, int x, int y, char c)
{
	int	xx;
	int	yy;
	int	base[2];
	int	pos[2];

	base[0] = x;
	base[1] = y;
	xx = 0;
	while (xx < 3)
	{
		yy = 0;
		while (yy < 3)
		{
			pos[0] = xx;
			pos[1] = yy;
			_door_corners(data, base, pos);
			_door_center(data, base, pos, isdooropen(c));
			if (c == M_DOOR_OBJ_O || c == M_DOOR_OBJ_C)
				_door_obj(data, base, pos, isdooropen(c));
			else if (c == M_DOOR_O || c == M_DOOR_C)
				_door_normal(data, base, pos, isdooropen(c));
			yy++;
		}
		xx++;
	}
}
