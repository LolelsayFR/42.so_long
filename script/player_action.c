/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:51:19 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/03 23:46:49 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_action(t_mlx_data *data, int hit[5][3])
{
	int	i;

	ft_printf("ROOM X = %i ROOM Y = %i\n", data->room->r_pos[0], data->room->r_pos[1]);
	i = 1;
	while (i <= 5)
	{
		if (data->room->map[(hit[i][1] - 1)][(hit[i][0] - 1)] == M_DOOR_C)
		{
			data->room->map[(hit[i][1] - 1)][(hit[i][0] - 1)] = M_DOOR_O;
			data->map->visited_map[(hit[i][1] - 1) + (data->room->r_pos[1] * 4)]
			[(hit[i][0] - 1) + (data->room->r_pos[0] * 4)] = M_DOOR_O;
		}
		if (data->room->map[(hit[i][1] - 1)][(hit[i][0] - 1)] == M_DOOR_OBJ_C
			&& data->player->obj == data->map->obj)
		{
			data->room->map[(hit[i][1] - 1)][(hit[i][0] - 1)] = M_DOOR_OBJ_O;
			data->map->visited_map[(hit[i][1] - 1) + (data->room->r_pos[1] * 4)]
			[(hit[i][0] - 1) + (data->room->r_pos[0] * 4)] = M_DOOR_OBJ_O;
		}
		i++;
	}
}

void	chest_action(t_mlx_data *data, int x, int y)
{
	if (data->room->map[(y - 1)][(x - 1)] == M_CH_OBJ_C)
	{
		data->room->map[(y - 1)][(x - 1)] = M_CH_OBJ_O;
		data->map->visited_map[(y - 1) + (data->room->r_pos[1] * 4)]
		[(x - 1) + (data->room->r_pos[0] * 4)] = M_CH_OBJ_O;
		data->player->obj++;
	}
	if (data->room->map[(y - 1)][(x - 1)] == M_CH_HP_C)
	{
		data->room->map[(y - 1)][(x - 1)] = M_CH_HP_O;
		data->map->visited_map[(y - 1) + (data->room->r_pos[1] * 4)]
		[(x - 1) + (data->room->r_pos[0] * 4)] = M_CH_HP_O;
		data->player->hp++;
	}
}
