/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:14:18 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/04 15:45:18 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_event(fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img->image);
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

void	shift_keys(int key, fdf *data)
{
	if (key == XK_h)
		data->shift_x -= 10;
	if (key == XK_j)
		data->shift_y += 10;
	if (key == XK_k)
		data->shift_y -= 10;
	if (key == XK_l)
		data->shift_x += 10;
}

void	perspective_zoom(int key, fdf *data)
{
	if (key == XK_3)
	{
		data->angle->x = 0.8;
		data->angle->y = 0.4;
		data->angle->z = 0.0;
	}
	if (key == XK_4)
	{
		data->angle->x = 0.0;
		data->angle->y = 0.0;
		data->angle->z = 0.0;
	}
	if (key == XK_minus)
		data->zoom -= 1;
	if (key == XK_equal)
		data->zoom += 1;
}

void	rotate_depth(int key, fdf *data)
{
	if (key == XK_9)
		data->angle->x -= 0.1;
	if (key == XK_0)
		data->angle->x += 0.1;
	if (key == XK_bracketleft)
		data->angle->y -= 0.1;
	if (key == XK_bracketright)
		data->angle->y += 0.1;
	if (key == XK_7)
		data->angle->z -= 0.1;
	if (key == XK_8)
		data->angle->z += 0.1;
	if (key == XK_1)
		data->depth -= 1;
	if (key == XK_2)
		data->depth += 1;
}

void	instructions_put(fdf *data)
{
	char	*tutorial;
	char	*tutorial1;
	char	*tutorial2;
	char	*tutorial3;
	char	*line;

	line = "*|-------------------------------------------------------|*";
	tutorial = "*| up = k ### down = j ### left = h ### right = l        |*";
	tutorial1 = "*| zoom in = = ### zoom out = - ### rotate x = [ or ]    |*";
	tutorial2 = "*| rotate y = 9 or 0 ### rotate z = 7 or 8               |*";
	tutorial3 = "*| depth change = 1 or 2 ### perspective change = 3 or 4 |*";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xff0000, line);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 25, 0xff0000, tutorial);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 40, 0xff0000, tutorial1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 55, 0xff0000, tutorial2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0xff0000, tutorial3);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 85, 0xff0000, line);
}
