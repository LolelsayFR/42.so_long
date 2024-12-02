/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:07:47 by emaillet          #+#    #+#             */
/*   Updated: 2024/12/02 01:31:48 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_set_sprite(t_mlx_data *data, char *path)
{
	int			w;
	int			h;

	mlx_destroy_image(data->mlx_ptr, data->img->player);
	data->img->player = mlx_xpm_file_to_image(data->mlx_ptr, path, &w, &h);
}
