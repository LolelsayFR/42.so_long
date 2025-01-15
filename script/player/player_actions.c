/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:51:19 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 04:26:07 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	door_action2(t_mlx_data *data, int i)
{
	if (data->room->map[(data->hc[i][1] - 1)]
		[(data->hc[i][0] - 1)] == M_DOOR_C)
	{
		data->room->map[(data->hc[i][1] - 1)]
		[(data->hc[i][0] - 1)] = M_DOOR_O;
		data->map->visited_map[(data->hc[i][1] - 1)
			+ (data->room->r_pos[1] * 4)]
		[(data->hc[i][0] - 1) + (data->room->r_pos[0] * 4)] = M_DOOR_O;
	}
	if (data->room->map[(data->hc[i][1] - 1)]
		[(data->hc[i][0] - 1)] == M_DOOR_OBJ_C
		&& data->player->obj == data->map->obj)
	{
		data->room->map[(data->hc[i][1] - 1)]
		[(data->hc[i][0] - 1)] = M_DOOR_OBJ_O;
		data->map->visited_map[(data->hc[i][1] - 1)
			+ (data->room->r_pos[1] * 4)]
		[(data->hc[i][0] - 1) + (data->room->r_pos[0] * 4)] = M_DOOR_OBJ_O;
	}
}

void	door_action(t_mlx_data *data)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		door_action2(data, i);
		i++;
	}
	mlx_hud_render(data);
	data->player->player_step++;
	data->player->can_use = -1;
}

void	chest_action(t_mlx_data *data, int x, int y)
{
	if (data->room->map[(y - 1)][(x - 1)] == M_CH_OBJ_C)
	{
		data->room->map[(y - 1)][(x - 1)] = M_CH_OBJ_O;
		data->map->visited_map[(y - 1) + (data->room->r_pos[1] * 4)]
		[(x - 1) + (data->room->r_pos[0] * 4)] = M_CH_OBJ_O;
		data->player->obj++;
		data->player->taken = 2;
	}
	if (data->room->map[(y - 1)][(x - 1)] == M_CH_HP_C)
	{
		data->room->map[(y - 1)][(x - 1)] = M_CH_HP_O;
		data->map->visited_map[(y - 1) + (data->room->r_pos[1] * 4)]
		[(x - 1) + (data->room->r_pos[0] * 4)] = M_CH_HP_O;
		data->player->potion++;
		data->player->taken = 1;
	}
	if (data->room->map[(y - 1)][(x - 1)] == M_FINISH)
	{
		if (data->player->obj == data->map->obj)
			data->state = 1;
	}
	mlx_hud_render(data);
	data->player->player_step++;
	data->player->can_use = -1;
}

void	player_actions(t_mlx_data *data)
{
	char	*set;

	if (data->player->can_use != 1 || data->control->primary != 1)
		return ;
	set = MAP_CLOSE_DOOR;
	if (ft_strchr(set, data->room->map[(data->hc[1][1] - 1)]
		[(data->hc[1][0] - 1)])
	|| ft_strchr(set, data->room->map[(data->hc[2][1] - 1)]
			[(data->hc[2][0] - 1)])
	|| ft_strchr(set, data->room->map[(data->hc[3][1] - 1)]
			[(data->hc[3][0] - 1)])
	|| ft_strchr(set, data->room->map[(data->hc[4][1] - 1)]
			[(data->hc[4][0] - 1)]))
		return (door_action(data));
	set = MAP_ACTION;
	if (ft_strchr(set, data->room->map[(data->hc[0][1] - 1)]
		[(data->hc[0][0] - 1)]))
		return (chest_action(data, data->hc[0][0], data->hc[0][1]));
}
