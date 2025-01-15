/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:26:09 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/15 05:44:48 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_put_room_bg(t_mlx_data *data)
{
	int			w;
	int			h;
	static int	init = 0;

	if (init == 0 || !data->img->room_bg)
	{
		init = 1;
		data->img->room_bg = mlx_xpm_file_to_image(data->mlx_ptr,
				ROOM_BG, &w, &h);
	}
	if (!data->img->room_bg)
		ft_printf("Cant access player data");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->room_bg, VIEW_X, VIEW_Y);
}

void	room_print(t_room *room)
{
	int	i;

	i = 0;
	ft_printf(YEL"[Room Init]\n"RES);
	while (i < 5)
	{
		ft_printf("%s", room->map[i]);
		i++;
	}
	ft_printf("\n");
}

int	player_coordinate(int coor)
{
	return ((coor / TILE_SIZE + 2) / 3 + 1);
}

int	isdooropen(char c)
{
	int	isopen;

	if (c == M_DOOR_O || c == M_DOOR_OBJ_O)
		isopen = 2;
	else
		isopen = 0;
	return (isopen);
}
