/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:03 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/30 01:43:08 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx_data	data;

	data.player = malloc(sizeof(t_player));
	data.control = malloc(sizeof(t_control));
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr || !data.control || !data.player)
		return (RETURN_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "So Long");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (RETURN_ERROR);
	}
	player_init(&data);
	mlx_render(&data);
	mlx_hook(data.win_ptr, 17, 0, mlx_close, &data);
	mlx_hook(data.win_ptr, 2, KeyPressMask, handle_input, &data);
	mlx_key_hook(data.win_ptr, handle_input_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, mlx_render, &data);
	mlx_loop(data.mlx_ptr);
	mlx_close(&data);
	return (0);
}

int	mlx_close(t_mlx_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->player);
	free(data->control);
	exit(0);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		mlx_close(data);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		data->control->right = 1;
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		data->control->left = 1;
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		data->control->up = 1;
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		data->control->down = 1;
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		data->control->shift = 1;
	else if (keysym == XK_space || keysym == XK_Control_R)
		data->control->use = 1;
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	handle_input_keyrelease(int keysym, t_mlx_data *data)
{
	if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		data->control->right = 0;
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		data->control->left = 0;
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		data->control->up = 0;
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		data->control->down = 0;
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		data->control->shift = 0;
	else if (keysym == XK_space || keysym == XK_Control_R)
		data->control->use = 0;
	ft_printf("The %d key has been released\n\n", keysym);
	return (0);
}

int	mlx_render(t_mlx_data *data)
{
	player_move(data);
	if (data->updated)
	{
		mlx_put_background(data);
		mlx_put_player(data, data->player->pos_x, data->player->pos_y);
	}
	data->updated = 0;
	return (0);
}
