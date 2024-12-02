/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:36:08 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/02 01:05:53 by emaillet         ###   ########.fr       */
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
	int			w;
	int			h;
	static int	init = 0;

	if (init == 0 || !data->img->player)
	{
		init = 1;
		data->img->player = mlx_xpm_file_to_image(data->mlx_ptr,
				PLAYER, &w, &h);
	}
	if (!data->img->player)
		ft_printf("Cant access player data");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->player, x, y);
}
