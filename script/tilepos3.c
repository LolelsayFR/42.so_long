/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilepos3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:32:13 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/07 12:37:17 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_errorpos(t_mlx_data *data, int x, int y)
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
