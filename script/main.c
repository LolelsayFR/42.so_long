/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:03 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/28 07:16:22 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (RETURN_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			WIDTH, HEIGHT, "So Long");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (RETURN_ERROR);
	}
	color_map(&data, WIDTH, HEIGHT);
	mlx_putimg(&data, "./sprite/saturn.xpm");
	mlx_hook(data.win_ptr, 17, 0, mlx_close, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	mlx_close(&data);
	return (0);
}

void	mlx_putimg(t_mlx_data *data, char *path)
{
	void	*image;
	int		img_width;
	int		img_height;

	image = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width, &img_height);
	if (!image)
	{
		ft_printf("Error: Unable to load image from path: %s\n", path);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return ;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image, 0, 0);
	mlx_destroy_image(data->mlx_ptr, image);
}

int	mlx_close(t_mlx_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
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

int	color_map(t_mlx_data *data, int w, int h)
{
	int	x;
	int	y;
	int	color;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = (x * 255) / w + ((((w - x) * 255) / w) << 16)
				+ (((y * 255) / h) << 8);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		}
	}
	return (1);
}
