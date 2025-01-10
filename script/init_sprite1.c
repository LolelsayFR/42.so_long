/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:44:09 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 04:56:52 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sprites_init_ui(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->enemy = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"enemy.xpm", &w, &h);
	data->img->spike = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"spikes.xpm", &w, &h);
	data->img->heart = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"heart.xpm", &w, &h);
	data->img->trophy = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"finish.xpm", &w, &h);
	data->img->anim_screamer[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"scream/0.xpm", &w, &h);
	data->img->anim_screamer[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"scream/1.xpm", &w, &h);
	data->img->anim_screamer[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"scream/2.xpm", &w, &h);
	data->img->shield = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"shield.xpm", &w, &h);
	data->img->popup[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"popup/lose.xpm", &w, &h);
	data->img->popup[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"popup/win.xpm", &w, &h);
	return (sprites_init_ui2(data));
}

int	sprites_init_ui2(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->potion = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"potion.xpm", &w, &h);
	data->img->relic[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"relic/0.xpm", &w, &h);
	data->img->relic[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"relic/1.xpm", &w, &h);
	data->img->relic[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"relic/2.xpm", &w, &h);
	data->img->relic[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"relic/3.xpm", &w, &h);
	data->img->relic[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"relic/4.xpm", &w, &h);
	data->img->relic[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"relic/5.xpm", &w, &h);
	data->img->relic[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"relic/6.xpm", &w, &h);
	data->img->relic[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"relic/7.xpm", &w, &h);
	data->img->popup[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"popup/pause.xpm", &w, &h);
	return (1);
}

void	sprite_clear_ui(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->shield);
	mlx_destroy_image(data->mlx_ptr, data->img->trophy);
	mlx_destroy_image(data->mlx_ptr, data->img->heart);
	mlx_destroy_image(data->mlx_ptr, data->img->spike);
	mlx_destroy_image(data->mlx_ptr, data->img->enemy);
	mlx_destroy_image(data->mlx_ptr, data->img->relic[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->relic[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->relic[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->relic[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->relic[4]);
	mlx_destroy_image(data->mlx_ptr, data->img->relic[5]);
	mlx_destroy_image(data->mlx_ptr, data->img->relic[6]);
	mlx_destroy_image(data->mlx_ptr, data->img->relic[7]);
	mlx_destroy_image(data->mlx_ptr, data->img->anim_screamer[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->anim_screamer[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->anim_screamer[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->potion);
	mlx_destroy_image(data->mlx_ptr, data->img->popup[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->popup[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->popup[2]);
}
