/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_tilemap2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 04:39:54 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/04 05:32:20 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sprites_init_floors(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->tilemap->floor[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"floors/down_left.xpm", &w, &h);
	data->img->tilemap->floor[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"floors/down.xpm", &w, &h);
	data->img->tilemap->floor[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"floors/left.xpm", &w, &h);
	data->img->tilemap->floor[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"floors/up_left.xpm", &w, &h);
	data->img->tilemap->floor[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"floors/up.xpm", &w, &h);
	data->img->tilemap->floor[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"floors/down_right.xpm", &w, &h);
	data->img->tilemap->floor[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"floors/right.xpm", &w, &h);
	data->img->tilemap->floor[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"floors/up_right.xpm", &w, &h);
	data->img->tilemap->floor[8] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"floors/floor.xpm", &w, &h);
	return (sprites_init_other(data));
}

int	sprites_init_other(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->tilemap->chest[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"chest/chest.xpm", &w, &h);
	data->img->tilemap->chest[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"chest/chest_open.xpm", &w, &h);
	data->img->tilemap->red_chest[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"chest/red_chest.xpm", &w, &h);
	data->img->tilemap->red_chest[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"chest/red_chest_open.xpm", &w, &h);
	return (1);
}

void	sprite_clear_tilemap1(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_down[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_down[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_down[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_down[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_left[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_left[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_left[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_left[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_up[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_up[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_up[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_up[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_right[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_right[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_right[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->door_right[3]);
	sprite_clear_tilemap2(data);
}

void	sprite_clear_tilemap2(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_up[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_up[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_up[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_up[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_down[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_down[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_down[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_down[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_left[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_left[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_left[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_left[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_right[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_right[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_right[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->end_right[3]);
	sprite_clear_tilemap3(data);
}

void	sprite_clear_tilemap3(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->wall[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->wall[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->wall[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->wall[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->wall[4]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->wall[5]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->wall[6]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->wall[7]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->floor[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->floor[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->floor[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->floor[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->floor[4]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->floor[5]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->floor[6]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->floor[7]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->floor[8]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->chest[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->chest[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->red_chest[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->tilemap->red_chest[1]);
}
