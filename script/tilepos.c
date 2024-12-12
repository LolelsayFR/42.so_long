/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilepos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:17:01 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/12 15:33:05 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_tilepos(t_mlx_data *data, int x, int y, char c)
{
	if (c == '.' || c == '@' || c == '$')
		map_floorpos(data, x, y);
	else if (c == 'W')
		map_wallpos(data, x, y);
	else if (c == '~' || c == '-' || c == ';' || c == ':')
		map_chestpos(data, x, y, c);
	else if (c == 'D' || c == 'E' || c == 'd' || c == 'e')
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
	if (c == 'e' || c == 'd')
		xy[4] = 1;
	if (x >= 0 && y >= 1 && x <= 5 && y <= 5)
	{
		x = (x * 3) - 2;
		y = (y * 3) - 2;
		while (xy[0] < 3)
		{
			xy[1] = 0;
			while (xy[1] < 3)
			{
				if (c == 'E' || c == 'e')
					map_doorpos3(data, x - xy[0], y - xy[1], xy);
				else
					map_doorpos2(data, x - xy[0], y - xy[1], xy);
				xy[1]++;
			}
			xy[0]++;
		}
	}
}

void	map_chestpos(t_mlx_data *data, int x, int y, char c)
{
	int	xy[4];

	xy[0] = 0;
	xy[3] = c;
	if (x >= 0 && y >= 1 && x <= 5 && y <= 5)
	{
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
