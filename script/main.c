/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:03 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/28 00:49:13 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (RETURN_ERROR);
	data.win_ptr = mlx_new_window(
			data.mlx_ptr,
			WIDTH,
			HEIGHT,
			"So Long");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (RETURN_ERROR);
	}
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	mlx_close(&data);
	return (0);
}

void	mlx_close(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_close(data);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}
