/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:36:08 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/04 02:08:52 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put_background(t_mlx_data *data)
{
	int			w;
	int			h;
	static int	init = 0;

	if (init == 0 || !data->img->bg)
	{
		init = 1;
		data->img->bg = mlx_xpm_file_to_image(data->mlx_ptr, BG, &w, &h);
	}
	if (!data->img->bg)
		ft_printf("Cant access background data");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->bg, 0, 0);
}

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

void	mlx_put_hud_bg(t_mlx_data *data)
{
	int			w;
	int			h;
	static int	init = 0;

	if (init == 0 || !data->img->hud_bg)
	{
		init = 1;
		data->img->hud_bg = mlx_xpm_file_to_image(data->mlx_ptr,
				HUD_BG, &w, &h);
	}
	if (!data->img->hud_bg)
		ft_printf("Cant access player data");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->hud_bg, HUD_X, HUD_Y);
}

void	mlx_put_player(t_mlx_data *data, int x, int y)
{
	static int	init = 0;

	if (init == 0 || !data->img->player)
	{
		init = 1;
		ft_printf(YEL"Need player init\n"RES);
	}
	else
		draw_image(data->img->player, data, x, y);
}

void	draw_image(t_img *img, t_mlx_data *data, int x_offset, int y_offset)
{
	int				x;
	int				y;
	unsigned int	color;
	char			*pixel_data;
	int				pixel_pos;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		pixel_data = img->data + y * img->size_line;
		while (x < img->width)
		{
			pixel_pos = x * (img->bpp / 8);
			color = *((unsigned int *)(pixel_data + pixel_pos));
			if (color != 0xFF000000)
			{
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x
					+ x_offset, y + y_offset, color);
			}
			x++;
		}
		y++;
	}
}
