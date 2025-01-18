/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:51:19 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/18 17:01:09 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_hitbox(t_mlx_data *data, int x, int y)
{
	if (player_colider(data, x, y))
		return (0);
	if (player_hitbox_door(data, x, y))
		return (0);
	return (1);
}

int	player_hitbox_door(t_mlx_data *data, int x, int y)
{
	int		hit[5][3];
	char	*set;

	hit[0][0] = player_coordinate(x - VIEW_X + HITBOX_W);
	hit[0][1] = player_coordinate(y - VIEW_Y + HITBOX_H);
	hit[1][0] = player_coordinate(x - VIEW_X + HITBOX_W);
	hit[1][1] = player_coordinate(y - VIEW_Y);
	hit[2][0] = player_coordinate(x - VIEW_X);
	hit[2][1] = player_coordinate(y - VIEW_Y + HITBOX_H);
	hit[3][0] = player_coordinate(x - VIEW_X);
	hit[3][1] = player_coordinate(y - VIEW_Y);
	set = MAP_OPEN_DOOR;
	if (((ft_strchr(set, data->room->map[(hit[1][1] - 1)][(hit[1][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[2][1] - 1)][(hit[2][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[3][1] - 1)][(hit[3][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[0][1] - 1)][(hit[0][0] - 1)]))
	) && door_check(x - VIEW_X + HITBOX_W / 2, y - VIEW_X + HITBOX_H / 2))
		return (1);
	return (0);
}

int	player_colider(t_mlx_data *data, int x, int y)
{
	int		hit[5][3];
	char	*set;

	hit[0][0] = player_coordinate(x - VIEW_X + HITBOX_W);
	hit[0][1] = player_coordinate(y - VIEW_Y + HITBOX_H);
	hit[1][0] = player_coordinate(x - VIEW_X + HITBOX_W);
	hit[1][1] = player_coordinate(y - VIEW_Y);
	hit[2][0] = player_coordinate(x - VIEW_X);
	hit[2][1] = player_coordinate(y - VIEW_Y + HITBOX_H);
	hit[3][0] = player_coordinate(x - VIEW_X);
	hit[3][1] = player_coordinate(y - VIEW_Y);
	set = MAP_COLIDE;
	if (ft_strchr(set, data->room->map[(hit[1][1] - 1)][(hit[1][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[2][1] - 1)][(hit[2][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[3][1] - 1)][(hit[3][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[0][1] - 1)][(hit[0][0] - 1)]))
		return (1);
	return (0);
}

int	door_check(int x, int y)
{
	if ((x > 90 && x < 120) || (x > 210 && x < 240) || (x > 310 && x < 350)
		|| (y > 70 && y < 100) || (y > 190 && y < 225) || (y > 300 && y < 340))
		return (0);
	return (1);
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
