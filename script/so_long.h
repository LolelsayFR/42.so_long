/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:31 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/28 07:04:23 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include "../modules/libft/libft.h"
# include "../modules/minilibx-linux/mlx.h"
# include "../modules/minilibx-linux/mlx_int.h"
# include "../modules/ft_printf/func/ft_printf.h"
# include "../modules/get_next_line/get_next_line_bonus.h"

# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define RES  "\x1B[0m"

# define RETURN_ERROR	-1
# define WIDTH			960
# define HEIGHT			540

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

int		handle_input(int keysym, t_mlx_data *data);
int		mlx_close(t_mlx_data *data);
void	mlx_putimg(t_mlx_data *data, char *path);
int		color_map(t_mlx_data *data, int w, int h);

#endif
