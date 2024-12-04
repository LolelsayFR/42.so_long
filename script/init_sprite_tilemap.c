/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_tilemap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:09:53 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/04 05:23:12 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sprites_init_door1(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->tilemap = malloc(sizeof(t_sprites_tilemap));
	data->img->tilemap->door_down[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_down01.xpm", &w, &h);
	data->img->tilemap->door_down[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_down02.xpm", &w, &h);
	data->img->tilemap->door_down[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_down03.xpm", &w, &h);
	data->img->tilemap->door_down[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_down022.xpm", &w, &h);
	data->img->tilemap->door_left[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_left01.xpm", &w, &h);
	data->img->tilemap->door_left[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_left02.xpm", &w, &h);
	data->img->tilemap->door_left[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_left03.xpm", &w, &h);
	data->img->tilemap->door_left[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_left022.xpm", &w, &h);
	return (sprites_init_door2(data));
}

int	sprites_init_door2(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->tilemap->door_up[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_up01.xpm", &w, &h);
	data->img->tilemap->door_up[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_up02.xpm", &w, &h);
	data->img->tilemap->door_up[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_up03.xpm", &w, &h);
	data->img->tilemap->door_up[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_up022.xpm", &w, &h);
	data->img->tilemap->door_right[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_right01.xpm", &w, &h);
	data->img->tilemap->door_right[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_right02.xpm", &w, &h);
	data->img->tilemap->door_right[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_right03.xpm", &w, &h);
	data->img->tilemap->door_right[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/base/door_right022.xpm", &w, &h);
	return (sprites_init_door3(data));
}

int	sprites_init_door3(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->tilemap->end_up[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_up01.xpm", &w, &h);
	data->img->tilemap->end_up[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_up02.xpm", &w, &h);
	data->img->tilemap->end_up[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_up03.xpm", &w, &h);
	data->img->tilemap->end_up[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_up022.xpm", &w, &h);
	data->img->tilemap->end_down[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_down01.xpm", &w, &h);
	data->img->tilemap->end_down[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_down02.xpm", &w, &h);
	data->img->tilemap->end_down[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_down03.xpm", &w, &h);
	data->img->tilemap->end_down[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_down022.xpm", &w, &h);
	return (sprites_init_door4(data));
}

int	sprites_init_door4(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->tilemap->end_left[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_left01.xpm", &w, &h);
	data->img->tilemap->end_left[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_left02.xpm", &w, &h);
	data->img->tilemap->end_left[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_left03.xpm", &w, &h);
	data->img->tilemap->end_left[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_left022.xpm", &w, &h);
	data->img->tilemap->end_right[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_right01.xpm", &w, &h);
	data->img->tilemap->end_right[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_right02.xpm", &w, &h);
	data->img->tilemap->end_right[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_right03.xpm", &w, &h);
	data->img->tilemap->end_right[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"doors/end/door_end_right022.xpm", &w, &h);
	return (sprites_init_wall(data));
}

int	sprites_init_wall(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->tilemap->wall[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"walls/wall_down_left.xpm", &w, &h);
	data->img->tilemap->wall[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"walls/wall_down.xpm", &w, &h);
	data->img->tilemap->wall[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"walls/wall_right.xpm", &w, &h);
	data->img->tilemap->wall[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"walls/wall_up_right.xpm", &w, &h);
	data->img->tilemap->wall[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"walls/wall_down_right.xpm", &w, &h);
	data->img->tilemap->wall[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"walls/wall_left.xpm", &w, &h);
	data->img->tilemap->wall[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"walls/wall_up_left.xpm", &w, &h);
	data->img->tilemap->wall[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"walls/wall_up.xpm", &w, &h);
	return (sprites_init_floors(data));
}
