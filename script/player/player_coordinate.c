/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coordinate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:51:19 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/10 08:52:10 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_coordinate(int coor)
{
	return ((coor + TILE_SIZE) / TILE_SIZE);
}

int	door_check(int x, int y)
{
	if ((x > 90 && x < 120) || (x > 210 && x < 240) || (x > 310 && x < 350)
		|| (y > 70 && y < 100) || (y > 190 && y < 225) || (y > 300 && y < 340))
		return (0);
	return (1);
}
