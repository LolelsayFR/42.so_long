/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:26:09 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/04 02:40:53 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
