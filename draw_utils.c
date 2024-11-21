/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:42:25 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/03 18:50:43 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	maxi(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	init_steps(float *x_step, float *y_step, int *max, fdf *data)
{
	*x_step = data->matrix->x1 - data->matrix->x;
	*y_step = data->matrix->y1 - data->matrix->y;
	*max = maxi(mod(*x_step), mod(*y_step));
	*x_step /= *max;
	*y_step /= *max;
}

void	dda_algo(fdf *data)
{
	float	x_step;
	float	y_step;
	float	ratio;
	int		max;

	ratio = 0.01;
	init_steps(&x_step, &y_step, &max, data);
	while ((int)(data->matrix->x - data->matrix->x1) || (int)(data->matrix->y
			- data->matrix->y1))
	{
		if (data->matrix->x > 1000 || data->matrix->y > 1000
			|| data->matrix->x < 0 || data->matrix->y < 0)
			break ;
		my_pixel_put(data, data->matrix->x, data->matrix->y,
			interpolate_color(data->color, data->color1, ratio));
		data->matrix->x += x_step;
		data->matrix->y += y_step;
		ratio += 0.01;
		if (ratio >= 1.0)
			ratio = 1.0;
		max += max;
	}
}

void	draw_shift(fdf *data)
{
	data->matrix->x += data->shift_x;
	data->matrix->y += data->shift_y;
	data->matrix->x1 += data->shift_x;
	data->matrix->y1 += data->shift_y;
}
