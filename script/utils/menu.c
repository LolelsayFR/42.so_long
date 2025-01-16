/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:03 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/16 18:25:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pause_handle_input(t_mlx_data *data)
{
	static int	y = 0;

	if (data->control->up && !data->control->down && y == 1)
		y--;
	if (data->control->down && !data->control->up && y == 0)
		y++;
	draw_image(data->img->popup[2], data, WIDTH / 2 - 100, HEIGHT / 2 - 21);
	draw_image(data->img->menu, data, WIDTH / 2 - 200, HEIGHT / 2 + 42);
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH / 2 - 40,
		HEIGHT / 2 + 72, 0xFFFFFF, "Resume the game.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH / 2 - 35,
		HEIGHT / 2 + 102, 0xFFFFFF, "Quit the game.");
	if (y == 0)
		mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH / 2 - 40,
			HEIGHT / 2 + 72, 0x008000, "Resume the game.");
	else if (y == 1)
		mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH / 2 - 35,
			HEIGHT / 2 + 102, 0x008000, "Quit the game.");
	if (data->control->primary == 1 && y == 1)
		mlx_close(data);
	else if (data->control->primary == 1 && y == 0)
	{
		data->state = 0;
		draw_image(data->img->bg, data, 0, 0);
	}
}

void	end_handle_input(t_mlx_data *data)
{
	static int	i = 0;

	i++;
	if (i > FPS)
		mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH / 2 - 62,
			HEIGHT / 2 + 16, 0xFFFFFF, "Space to quit the game.");
	if (data->control->primary == 1 && i > FPS)
		mlx_close(data);
}
