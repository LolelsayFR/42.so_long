/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:55:52 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/07 08:27:47 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_close(t_mlx_data *data)
{
	map_free(data);
	free(data->control);
	sprite_clear_player(data);
	free(data->player->inventory);
	free(data->player);
	sprite_clear_tilemap1(data);
	free(data->img->tilemap);
	mlx_destroy_image(data->mlx_ptr, data->img->hud_bg);
	mlx_destroy_image(data->mlx_ptr, data->img->bg);
	free(data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
