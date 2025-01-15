/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:00:26 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 10:35:36 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_hud_render(t_mlx_data *data)
{
	char	*temp[3];

	temp[0] = ft_itoa(data->player->player_step);
	mlx_put_hud_bg(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		650, 400, 0xFFFFFF, temp[0]);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		650, 458, 0xFFFFFF, data->timer);
	free(temp[0]);
	temp[0] = ft_itoa(data->player->obj);
	temp[1] = ft_itoa(data->map->obj);
	temp[2] = ft_strjoin(temp[0], "/");
	data->obj = ft_strjoin(temp[2], temp[1]);
	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		807, 458, 0xFFFFFF, data->obj);
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
		807, 400, 0xFFFFFF, data->potion);
	free(data->potion);
	heart_hud(data);
	map_print(data->map->visited_map, data);
}

void	heart_hud(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->player->hp)
		draw_image(data->img->heart, data, 585 + (i * 35), 62);
}

void	popup_hud(t_mlx_data *data)
{
	if (data->inpopup == 0)
	{
		mlx_render(data);
		data->inpopup = 1;
	}
	if (data->state == 1)
	{
		draw_image(data->img->popup[0], data, WIDTH / 2 - 100, HEIGHT / 2 - 21);
		end_handle_input(data);
	}
	else if (data->state == 2)
	{
		draw_image(data->img->popup[1], data, WIDTH / 2 - 100, HEIGHT / 2 - 21);
		end_handle_input(data);
	}
	else if (data->state == 3)
		pause_handle_input(data);
}
