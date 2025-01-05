/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:19:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/04 21:23:20 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	*enemy_create(t_mlx_data *data, char c, int x, int y)
{
	int		id;
	t_enemy	*enemy;

	id = 0;
	while ((data->enemy)[id] != NULL)
		id++;
	(void)id;
	(void)c;
	(void)x;
	(void)y;
	enemy = NULL;
	return (enemy);
}

t_enemy	*enemy_kill(t_mlx_data *data, int id)
{
	(void)id;
	(void)data;
	return (NULL);
}
