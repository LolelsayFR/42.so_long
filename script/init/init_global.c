/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:30:28 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/15 08:16:56 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	data_init(t_mlx_data *data, char *map_path)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(-1);
	data->control = ft_calloc(1, sizeof(t_control));
	data->img = ft_calloc(1, sizeof(t_sprites));
	data->map = ft_calloc(1, sizeof(t_map));
	data->room = ft_calloc(1, sizeof(t_room));
	data->floodfill = ft_calloc(1, sizeof(t_flood));
	data->control->up = 0;
	data->control->down = 0;
	data->control->right = 0;
	data->control->left = 0;
	data->control->primary = 0;
	data->control->sprint = 0;
	data->map->path = map_path;
	data->map->obj = 0;
	data->state = 0;
	data_init2(data);
}

void	data_init2(t_mlx_data *data)
{
	sprites_init_player1(data);
	sprites_init_door1(data);
	sprites_init_ui(data);
	sprites_init_minimap(data);
	player_init(data);
	data->map->isvalid = map_init(data);
	data->room->r_pos[0] = -1;
	data->room->r_pos[1] = -1;
	data->timer = ft_calloc(1, sizeof(char));
	mlx_timer(data);
	data->frames = 0;
	data->inpopup = 0;
	data->hc[0][0] = 0;
	data->hc[0][1] = 0;
}

void	player_init(t_mlx_data *data)
{
	data->player = ft_calloc(1, sizeof(t_player));
	data->player->speed = DEFAULT_SPEED;
	data->player->sprint = DEFAULT_SPRINT;
	data->player->hp = DEFAULT_HP;
	data->player->pos_x = 100;
	data->player->pos_y = 100;
	data->player->obj = 0;
	data->player->player_step = 0;
	data->map->player_pos[0] = 1;
	data->map->player_pos[1] = 1;
	data->player->can_use = 1;
}

void	mlx_timer(t_mlx_data *data)
{
	static int	sec = 0;
	static int	min = 0;
	char		*time[2];
	char		*temp;

	sec++;
	if (sec == 60)
	{
		sec = 0;
		min++;
	}
	time[0] = ft_itoa(min);
	time[1] = ft_itoa(sec);
	free(data->timer);
	temp = ft_strjoin(time[0], " min ");
	data->timer = ft_strjoin(temp, time[1]);
	free(temp);
	temp = ft_strjoin(data->timer, " s");
	free(data->timer);
	data->timer = ft_strdup(temp);
	free (temp);
	free(time[0]);
	free(time[1]);
}
