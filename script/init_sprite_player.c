/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:44:09 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/04 22:10:44 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sprites_init_player1(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->player_anim = malloc(sizeof(t_sprites_player));
	data->img->player_anim->up[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/up1.xpm", &w, &h);
	data->img->player_anim->up[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/up2.xpm", &w, &h);
	data->img->player_anim->up[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/up3.xpm", &w, &h);
	data->img->player_anim->up[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/up4.xpm", &w, &h);
	data->img->player_anim->down[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/down1.xpm", &w, &h);
	data->img->player_anim->down[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/down2.xpm", &w, &h);
	data->img->player_anim->down[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/down3.xpm", &w, &h);
	data->img->player_anim->down[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/down4.xpm", &w, &h);
	return (sprites_init_player2(data));
}

int	sprites_init_player2(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img->player_anim->left[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/left1.xpm", &w, &h);
	data->img->player_anim->left[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/left2.xpm", &w, &h);
	data->img->player_anim->left[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/left3.xpm", &w, &h);
	data->img->player_anim->left[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/left4.xpm", &w, &h);
	data->img->player_anim->right[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/right1.xpm", &w, &h);
	data->img->player_anim->right[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/right2.xpm", &w, &h);
	data->img->player_anim->right[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/right3.xpm", &w, &h);
	data->img->player_anim->right[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			PTH"player/right4.xpm", &w, &h);
	return (1);
}

void	sprite_clear_player(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->left[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->left[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->left[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->left[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->right[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->right[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->right[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->right[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->down[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->down[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->down[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->down[3]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->up[0]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->up[1]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->up[2]);
	mlx_destroy_image(data->mlx_ptr, data->img->player_anim->up[3]);
	free(data->img->player_anim);
}
