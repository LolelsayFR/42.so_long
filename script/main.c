/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:03 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 10:42:40 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac != 2)
		return (ft_printf(RED"[ERROR]\nPlease add map.\n"RES), RETURN_ERROR);
	check_map_path(av[1]);
	data_init(&data, av[1]);
	if (!data.mlx_ptr || !data.control || !data.player)
		return (RETURN_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "So Long");
	if (!data.win_ptr)
	{
		mlx_close(&data);
		return (RETURN_ERROR);
	}
	mlx_put_background(&data);
	mlx_render(&data);
	mlx_hook(data.win_ptr, 17, 0, mlx_close, &data);
	mlx_hook(data.win_ptr, 2, KeyPressMask, handle_input, &data);
	mlx_key_hook(data.win_ptr, handle_input_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, mlx_clock, &data);
	mlx_loop(data.mlx_ptr);
	mlx_close(&data);
	return (0);
}

void	action_cooldown(t_mlx_data *data)
{
	if (data->player->can_use == -1 && data->control->primary == 1)
	{
		data->player->cooldown = COOLDOWN;
		data->player->can_use = 0;
	}
	if (data->player->cooldown > 0)
		data->player->cooldown--;
	if (data->player->can_use == 0 && data->player->cooldown == 0)
		data->player->can_use = 1;
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape && data->state == 3)
		return (data->state = 0, draw_image(data->img->bg, data, 0, 0), 0);
	else if (keysym == XK_Escape && data->state == 0)
		return (data->state = 3, 0);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		data->control->right = 1;
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		data->control->left = 1;
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		data->control->up = 1;
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		data->control->down = 1;
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		data->control->sprint = 1;
	else if (keysym == XK_space)
		data->control->primary = 1;
	else if (keysym == XK_h || keysym == XK_H)
		data->control->heal = 1;
	if (DEBUG == 1)
		ft_printf(GRN"The %d key has been pressed\n"RES, keysym);
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
		data->control->sprint = 0;
	else if (keysym == XK_space || keysym == XK_Return)
		data->control->primary = 0;
	else if (keysym == XK_h || keysym == XK_H)
		data->control->heal = 0;
	mlx_hud_render(data);
	if (DEBUG == 1)
		ft_printf(RED"The %d key has been released\n"RES, keysym);
	return (0);
}

void	check_map_path(char *str)
{
	int			i;
	int			readed;
	char		*s;
	static char	*buff = NULL;

	i = ft_strlen(str);
	s = ft_substr(str, i - 4, i);
	if (ft_strncmp(s, ".ber", 4))
		return (free(s), ft_printf(RED"[ERROR]\nNot .ber map\n"RES), exit(-1));
	free(s);
	i = open(str, O_RDONLY);
	buff = malloc(1);
	readed = read(i, buff, 1);
	close(i);
	if (readed <= 0)
		return (free(buff), ft_printf(RED"[ERROR]\nEmpty map.\n"RES), exit(-1));
	free(buff);
}
