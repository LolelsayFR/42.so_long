/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:51:19 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/03 18:36:36 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_hitbox(t_mlx_data *data, int x, int y)
{
	int	xy[4];

	xy[0] = player_coordinate(x - VIEW_X);
	xy[1] = player_coordinate(y - VIEW_Y);
	xy[2] = player_coordinate(x - VIEW_X + HITBOX_W);
	xy[3] = player_coordinate(y - VIEW_Y + HITBOX_H);
	if (player_colider(data, xy))
		return (0);
	else if (player_hitbox_door(data, x, y, xy))
		return (0);
	return (1);
}

int	player_hitbox_door(t_mlx_data *data, int x, int y, int *xy)
{
	char	*set;

	set = "de";
	if (door_check(x - VIEW_X + HITBOX_W / 2, y - VIEW_X + HITBOX_H / 2))
	{
		if (ft_strchr(set, data->room->map[(xy[1] - 1)][(xy[0] - 1)]))
			return (1);
		else if (ft_strchr(set, data->room->map[(xy[3] - 1)][(xy[2] - 1)]))
			return (1);
	}
	return (0);
}

int	player_colider(t_mlx_data *data, int *xy)
{
	char	*set;

	set = "WDE";
	if (ft_strchr(set, data->room->map[(xy[1] - 1)][(xy[0] - 1)]))
		return (1);
	else if (ft_strchr(set, data->room->map[(xy[3] - 1)][(xy[2] - 1)]))
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
	int		hit[5][3];
	char	*set;

	hit[0][0] = player_coordinate(data->player->pos_x - VIEW_X + HITBOX_W / 2);
	hit[0][1] = player_coordinate(data->player->pos_y - VIEW_Y + HITBOX_H / 2);
	hit[1][0] = player_coordinate(data->player->pos_x - VIEW_X + HITBOX_W + 10);
	hit[1][1] = player_coordinate(data->player->pos_y - VIEW_Y + HITBOX_H / 2);
	hit[2][0] = player_coordinate(data->player->pos_x - VIEW_X - 20);
	hit[2][1] = player_coordinate(data->player->pos_y - VIEW_Y + HITBOX_H / 2);
	hit[3][0] = player_coordinate(data->player->pos_x - VIEW_X + HITBOX_W / 2);
	hit[3][1] = player_coordinate(data->player->pos_y - VIEW_Y + HITBOX_H + 10);
	hit[4][0] = player_coordinate(data->player->pos_x - VIEW_X + HITBOX_W / 2);
	hit[4][1] = player_coordinate(data->player->pos_y - VIEW_Y - 20);
	if (!data->control->primary)
		return ;
	set = "DE";
	if (ft_strchr(set, data->room->map[(hit[1][1] - 1)][(hit[1][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[2][1] - 1)][(hit[2][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[3][1] - 1)][(hit[3][0] - 1)])
	|| ft_strchr(set, data->room->map[(hit[4][1] - 1)][(hit[4][0] - 1)]))
		return (door_action(data, hit));
	set = ":~";
	if (ft_strchr(set, data->room->map[(hit[0][1] - 1)][(hit[0][0] - 1)]))
		return (chest_action(data, hit[0][0], hit[0][1]));
}
