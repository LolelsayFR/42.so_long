/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:31 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/27 18:58:15 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <signal.h>
# include "../modules/ft_printf/func/ft_printf.h"
# include "../modules/libft/libft.h"
# include "../modules/get_next_line/get_next_line.h"
# include "../modules/minilibx-linux/mlx.h"

# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define RES  "\x1B[0m"

void	signal_count(int sig);
void	client_init(pid_t server_pid, char *str);

#endif
