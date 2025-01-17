/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:59:00 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/17 23:59:31 by emaillet         ###   ########.fr       */
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

void	draw_player(t_img *img, t_mlx_data *data, int x_offset, int y_offset)
{
	int				x;
	int				y;
	unsigned int	color;
	char			*pixel_data;
	int				pixel_pos;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		pixel_data = img->data + y * img->size_line;
		while (++x < img->width)
		{
			pixel_pos = x * (img->bpp / 8);
			color = *((unsigned int *)(pixel_data + pixel_pos));
			if (color != 0xFF000000
				&& x + x_offset < VIEW_W + VIEW_X && x + x_offset > VIEW_X
				&& y + y_offset < VIEW_H + VIEW_Y && y + y_offset > VIEW_Y)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x
					+ x_offset, y + y_offset, color);
		}
	}
}
