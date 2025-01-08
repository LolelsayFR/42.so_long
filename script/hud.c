/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:00:26 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/08 11:57:54 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_hud_render(t_mlx_data *data)
{
	char	*temp[3];

	temp[0] = ft_itoa(data->player->player_step);
	mlx_put_hud_bg(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		650, 400, 0xFFFFFFFF, temp[0]);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		650, 458, 0xFFFFFFFF, data->timer);
	free(temp[0]);
	temp[0] = ft_itoa(data->player->obj);
	temp[1] = ft_itoa(data->map->obj);
	temp[2] = ft_strjoin(temp[0], "/");
	data->obj = ft_strjoin(temp[2], temp[1]);
	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		807, 458, 0xFFFFFFFF, data->obj);
	free(data->obj);
	mlx_hud_render2(data);
}

void	mlx_hud_render2(t_mlx_data *data)
{
	char	*temp[3];

	temp[0] = ft_itoa(data->player->potion);
	temp[1] = ft_itoa(data->map->potion);
	temp[2] = ft_strjoin(temp[0], "/");
	data->potion = ft_strjoin(temp[2], temp[1]);
	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		807, 400, 0xFFFFFFFF, data->potion);
	free(data->potion);
	heart_hud(data);
}

void	heart_hud(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->player->hp)
		draw_image(data->img->heart, data, 585 + (i * 35), 62);
}
