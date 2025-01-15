/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:44:09 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 08:11:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	sprites_init_minimap(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->mini = malloc(sizeof(t_sprites_minimap));
	data->img->mini->chest2_o = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/chest2_o.xpm", &w, &h);
	data->img->mini->chest2_c = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/chest2_c.xpm", &w, &h);
	data->img->mini->door2_o = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/door2_o.xpm", &w, &h);
	data->img->mini->chest_o = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/chest_o.xpm", &w, &h);
	data->img->mini->door2_c = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/door2_c.xpm", &w, &h);
	data->img->mini->chest_c = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/chest_c.xpm", &w, &h);
	data->img->mini->door_o = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/door_o.xpm", &w, &h);
	return (sprites_init_minimap2(data));
}

int	sprites_init_minimap2(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->mini->door_c = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/door_c.xpm", &w, &h);
	data->img->mini->spike = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/spike.xpm", &w, &h);
	data->img->mini->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/floor.xpm", &w, &h);
	data->img->mini->final = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/obj.xpm", &w, &h);
	data->img->mini->enemy = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/enemy.xpm", &w, &h);
	data->img->mini->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/wall.xpm", &w, &h);
	data->img->mini->player = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"mmap/player.xpm", &w, &h);
	return (1);
}

void	sprite_clear_minimap(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->mini->chest2_o);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->chest2_c);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->door2_o);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->chest_o);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->door2_c);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->chest_c);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->door_o);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->door_c);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->spike);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->floor);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->final);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->enemy);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->wall);
	mlx_destroy_image(data->mlx_ptr, data->img->mini->player);
	free(data->img->mini);
}
