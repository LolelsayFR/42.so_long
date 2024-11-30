/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:36:08 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/30 04:53:37 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put_background(t_mlx_data *data)
{
	t_img	*bg;
	int		w;
	int		h;

	bg = mlx_xpm_file_to_image(data->mlx_ptr, BACKGROUND, &w, &h);
	if (!bg)
		ft_printf("Cant access background data");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, bg, 0, 0);
	mlx_destroy_image(data->mlx_ptr, bg);
}

void	mlx_put_player(t_mlx_data *data, int x, int y)
{
	t_img	*bg;
	int		w;
	int		h;

	bg = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &w, &h);
	if (!bg)
		ft_printf("Cant access background data");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, bg, x, y);
	mlx_destroy_image(data->mlx_ptr, bg);
}
