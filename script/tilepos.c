/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilepos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:17:01 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/08 13:36:02 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_tilepos(t_mlx_data *data, int x, int y, char c)
{
	if (c == M_FLOOR || c == M_PLAYER || c == M_ENEMY
		|| c == M_FINISH || c == M_SPIKE)
		map_floorpos(data, x, y);
	else if (c == M_WALL)
		map_wallpos(data, x, y);
	else if (c == M_CH_HP_O || c == M_CH_HP_C
		|| c == M_CH_OBJ_O || c == M_CH_OBJ_C)
		map_chestpos(data, x, y, c);
	else if (c == M_DOOR_C || c == M_DOOR_OBJ_C
		|| c == M_DOOR_O || c == M_DOOR_OBJ_O)
		map_doorpos(data, x, y, c);
	else
		map_errorpos(data, x, y);
}

void	map_floorpos(t_mlx_data *data, int x, int y)
{
	int	xx;
	int	yy;

	xx = 0;
	if (x >= 1 && y >= 1 && x <= 5 && y <= 5)
	{
		x = (x * 3) - 2;
		y = (y * 3) - 2;
		while (xx < 3)
		{
			yy = 0;
			while (yy < 3)
			{
				map_floorpos2(data, x - xx, y - yy);
				yy++;
			}
			xx++;
		}
	}
}

void	map_doorpos(t_mlx_data *data, int x, int y, char c)
{
	int	xy[5];

	xy[0] = 0;
	xy[3] = c;
	xy[4] = 3;
	if (c == M_DOOR_O || c == M_DOOR_OBJ_O)
		xy[4] = 1;
	x = (x * 3) - 2;
	y = (y * 3) - 2;
	while (xy[0] < 3)
	{
		xy[1] = 0;
		while (xy[1] < 3)
		{
			if (c == M_DOOR_OBJ_O || c == M_DOOR_OBJ_C)
				map_doorpos3(data, x - xy[0], y - xy[1], xy);
			else
				map_doorpos2(data, x - xy[0], y - xy[1], xy);
			xy[1]++;
		}
		xy[0]++;
	}
}

void	map_chestpos(t_mlx_data *data, int x, int y, char c)
{
	int	xy[4];

	xy[0] = 0;
	xy[3] = c;
	if (!(x >= 0 && y >= 1 && x <= 5 && y <= 5))
		return (map_voidpos(data, x, y));
	x = (x * 3) - 2;
	y = (y * 3) - 2;
	while (xy[0] < 3)
	{
		xy[1] = 0;
		while (xy[1] < 3)
		{
			map_chestpos2(data, x - xy[0], y - xy[1], xy);
			xy[1]++;
		}
		xy[0]++;
	}
}

void	map_wallpos(t_mlx_data *data, int x, int y)
{
	int	xy[3];

	xy[0] = 0;
	if (x >= 0 && y >= 1 && x <= 5 && y <= 5)
	{
		x = (x * 3) - 2;
		y = (y * 3) - 2;
		while (xy[0] < 3)
		{
			xy[1] = 0;
			while (xy[1] < 3)
			{
				map_wallpos2(data, x, y, xy);
				xy[1]++;
			}
			xy[0]++;
		}
	}
}
