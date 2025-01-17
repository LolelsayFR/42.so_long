/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:57:11 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/17 21:04:32 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sl_logs(t_list *logs, char *str, ...)
{
	if (DEBUG)
		ft_printf("%s\n", str);
	ft_lstadd_back(&logs, ft_lstnew(ft_strdup(str)));
}

void	sl_logs_init(t_mlx_data *data)
{
	data->logs = ft_calloc(1, sizeof(t_logs));
	data->logs->floodfill = ft_calloc(1, sizeof(t_list));
	data->logs->map = ft_calloc(1, sizeof(t_list));
	data->logs->checker = ft_calloc(1, sizeof(t_list));
	data->logs->other = ft_calloc(1, sizeof(t_list));
	sl_logs(data->logs->floodfill, "\e[1m[Map Floodfills logs]"RES);
	sl_logs(data->logs->map, "\e[1m[Map Other logs]");
	sl_logs(data->logs->checker, "\e[1m[Map Checker logs]"RES);
	sl_logs(data->logs->other, "\e[1m[Global Other logs]"RES);
}

void	sl_logs_free(t_mlx_data *data)
{
	if (data->map->isvalid)
		sl_logs(data->logs->checker, GRN"[OK] Map check is valid."RES);
	else
		sl_logs(data->logs->checker, RED"[ERROR] Map check Ko."RES);
	if (data->floodfill->isvalid)
		sl_logs(data->logs->floodfill, GRN"[OK] Map floodfils is valid."RES);
	else
		sl_logs(data->logs->floodfill, RED"[ERROR] Map floodfills is Ko."RES);
	ft_putendl_fd("\n\n\n\e[1mLegend : \n"RES RED"[ERROR]\n"RES
		YEL"[WARNING]\n"RES"[INFO]\n"GRN"[VALIDATE]\n"RES, 2);
	sl_logs_print(data->logs->map);
	sl_logs_print(data->logs->checker);
	sl_logs_print(data->logs->floodfill);
	sl_logs_print(data->logs->other);
	ft_lstclear(&data->logs->floodfill, free);
	ft_lstclear(&data->logs->map, free);
	ft_lstclear(&data->logs->checker, free);
	ft_lstclear(&data->logs->other, free);
	free(data->logs);
}

void	sl_logs_print(t_list *lst)
{
	int	i;

	i = ft_lstsize(lst);
	if (!lst)
		return ;
	while (lst)
	{
		ft_putendl_fd(lst->content, 2);
		lst = lst->next;
	}
	if (i <= 2)
		ft_putendl_fd("Nothing here", 2);
	ft_putendl_fd("\n", 2);
}

void	sl_maplogs(t_mlx_data *data, char **tab)
{
	int			i;
	int			size_y;
	static int	init = 0;
	char		*s;

	i = 0;
	size_y = 0;
	while (tab[size_y] != NULL)
		size_y++;
	if (init == 1)
		return ;
	if (size_y > 80 || ft_strlen(tab[0]) > 160)
		return (init = 1, (void)sl_logs(data->logs->map,
				"Map is too big to be log."));
	while (i < size_y)
	{
		s = ft_strtrim(tab[i], "\n");
		sl_logs(data->logs->map, s);
		free (s);
		i++;
	}
}
