/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilepos3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:32:13 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/03 13:15:07 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_errorpos(t_mlx_data *data, int x, int y)
{
	int	xx;
	int	yy;

	xx = 0;
	x = (x * 3) - 2;
	y = (y * 3) - 2;
	while (xx < 3)
	{
		yy = 0;
		while (yy < 3)
		{
			mlx_put_tiles(data, data->img->tilemap->error, x - xx, y - yy);
			yy++;
		}
		xx++;
	}
}

void	map_voidpos(t_mlx_data *data, int x, int y)
{
	int	xx;
	int	yy;

	xx = 0;
	x = (x * 3) - 2;
	y = (y * 3) - 2;
	while (xx < 3)
	{
		yy = 0;
		while (yy < 3)
		{
			mlx_put_tiles(data, data->img->tilemap->voids, x - xx, y - yy);
			yy++;
		}
		xx++;
	}
}
