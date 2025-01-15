/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 06:35:20 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/15 02:33:03 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	minimap_print_choose2(t_mlx_data *data, int x, int y, char c)
{
	t_img	*tile;

	if (c == M_CH_HP_O)
		tile = data->img->mini->chest2_o;
	else if (c == M_CH_OBJ_C)
		tile = data->img->mini->chest_c;
	else if (c == M_CH_OBJ_O)
		tile = data->img->mini->chest_o;
	else if (c == M_SPIKE)
		tile = data->img->mini->spike;
	else if (c == M_ENEMY)
		tile = data->img->mini->enemy;
	else if (c == M_PLAYER)
		tile = data->img->mini->player;
	else if (c == M_FINISH)
		tile = data->img->mini->final;
	else
		tile = data->img->mini->floor;
	draw_image(tile, data, x, y);
}

void	minimap_print_choose(t_mlx_data *data, int x, int y, char c)
{
	t_img	*tile;

	if (c == M_WALL)
		tile = data->img->mini->wall;
	else if (c == M_DOOR_C)
		tile = data->img->mini->door_c;
	else if (c == M_DOOR_O)
		tile = data->img->mini->door_o;
	else if (c == M_DOOR_OBJ_O)
		tile = data->img->mini->door2_o;
	else if (c == M_DOOR_OBJ_C)
		tile = data->img->mini->door2_c;
	else if (c == M_CH_HP_C)
		tile = data->img->mini->chest2_c;
	else
		return (minimap_print_choose2(data, x, y, c));
	draw_image(tile, data, x, y);
}

void	minimap_print_one(t_mlx_data *data, int x, int y, char c)
{
	int	cx;
	int	cy;

	cx = ((x - 4 * data->map->player_pos[0]) * 6
			+ (MINMAP_MX - MINMAP_X) / 2) + MINMAP_X + 9;
	cy = ((y - 4 * data->map->player_pos[1]) * 6
			+ (MINMAP_MY - MINMAP_Y) / 2) + MINMAP_Y + 9;
	if (!ft_strchr(MAP_SET, c) || !(cx > MINMAP_X && cx < MINMAP_MX)
		|| !(cy > MINMAP_Y && cy < MINMAP_MY))
		return ;
	minimap_print_choose(data, cx, cy, c);
}

void	map_print(char **map, t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			minimap_print_one(data, j, i, map[i][j]);
			j++;
		}
		if (DEBUG)
			ft_printf("%s", map[i]);
		i++;
	}
}
