/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:36:08 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/15 02:50:11 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		ft_printf("Can't access background data");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->bg, 0, 0);
}

void	mlx_put_tiles(t_mlx_data *data, t_img *tile, int x, int y)
{
	int	rx;
	int	ry;

	if (!((x > 0 && x <= 11) && (y > 0 && y <= 11)))
		return ;
	if (!tile)
		ft_printf("Can't access tile data");
	rx = (x * TILE_SIZE) + VIEW_X - TILE_SIZE;
	ry = (y * TILE_SIZE) + VIEW_Y - TILE_SIZE;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, tile, rx, ry);
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
		ft_printf("Can't access player data");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->hud_bg, HUD_X, HUD_Y);
}

void	mlx_put_player(t_mlx_data *data, int x, int y)
{
	static int	i = 0;

	if (data->img->shield && data->player->hitted && (i % 10 < 2))
		draw_image(data->img->shield, data, x, y);
	if (data->player->taken || data->state == 1)
		draw_image(data->img->player_anim->take, data, x, y);
	else if (data->state == 2)
		draw_image(data->img->player_anim->dead, data, x, y);
	else if (data->img->player)
		draw_image(data->img->player, data, x, y);
	if (data->player->taken == 1)
		draw_image(data->img->potion, data, x + 14, y - 5);
	else if (data->player->taken == 2)
		draw_image(data->img->relic[data->frames % 8], data, x + 17, y - 5);
	else if (data->state == 1)
		draw_image(data->img->trophy, data, x + 16, y - 25);
	i++;
	if (i == FPS * 4)
		i = 0;
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
