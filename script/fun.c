/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:34:49 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/03 23:13:52 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	color_map(t_mlx_data *data, int w, int h)
{
	int	x;
	int	y;
	int	color;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = (x * 255) / w + ((((w - x) * 255) / w) << 16)
				+ (((y * 255) / h) << 8);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		}
	}
	return (1);
}

void	*mlx_new_image_alpha(t_xvar *xvar,int width, int height)
{
	t_img	*img;

	img = mlx_new_image(xvar, width, height);
	if (img)
		img->pict = XRenderCreatePicture(xvar->display, img->pix,
										 xvar->pict_format, 0, NULL);
	return (img);
}
