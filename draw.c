/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:24:13 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/04 14:58:05 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_zoom(fdf *data)
{
	data->matrix->x *= data->zoom;
	data->matrix->y *= data->zoom;
	data->matrix->x1 *= data->zoom;
	data->matrix->y1 *= data->zoom;
}

void	find_peak(fdf *data)
{
	int	i;
	int	j;
	int	z;

	z = 0;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (z < data->matrix->z_matrix[i][j])
				z = data->matrix->z_matrix[i][j];
			j++;
		}
		i++;
	}
	data->matrix->peak = z;
}

void	draw_mods(fdf *data)
{
	int	z;
	int	z1;

	data->matrix->x = (float)data->matrix->xx;
	data->matrix->x1 = (float)data->matrix->xx1;
	data->matrix->y = (float)data->matrix->yy;
	data->matrix->y1 = (float)data->matrix->yy1;
	z = data->matrix->z_matrix[(int)data->matrix->y][(int)data->matrix->x];
	z1 = data->matrix->z_matrix[(int)data->matrix->y1][(int)data->matrix->x1];
	color_managment(data);
	draw_zoom(data);
	data->center_x = (data->width / 2) * data->zoom;
	data->center_y = (data->height / 2) * data->zoom;
	data->center_z = 0;
	depth_perception(&z, data);
	depth_perception(&z1, data);
	rotation(&data->matrix->x, &data->matrix->y, &z, data);
	rotation(&data->matrix->x1, &data->matrix->y1, &z1, data);
	draw_shift(data);
	dda_algo(data);
}

void	draw(fdf *data)
{
	data->matrix->yy = 0;
	while (data->matrix->yy < data->height)
	{
		data->matrix->xx = 0;
		while (data->matrix->xx < data->width)
		{
			data->matrix->yy1 = data->matrix->yy;
			if (data->matrix->xx < data->width - 1)
			{
				data->matrix->xx1 = data->matrix->xx + 1;
				draw_mods(data);
			}
			data->matrix->xx1 = data->matrix->xx;
			if (data->matrix->yy < data->height - 1)
			{
				data->matrix->yy1 = data->matrix->yy + 1;
				draw_mods(data);
			}
			data->matrix->xx += 1;
		}
		data->matrix->yy += 1;
	}
}

void	error_x(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
