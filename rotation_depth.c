/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_depth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:17:39 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/03 18:52:44 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	z_rotation(float *x, float *y, int *z, fdf *data)
{
	*z = *z;
	*x = (*x - data->center_x) * cos(data->angle->z) - (*y - data->center_y)
		* sin(data->angle->z) + data->center_x;
	*y = (*x - data->center_x) * sin(data->angle->z) + (*y - data->center_y)
		* cos(data->angle->z) + data->center_y;
}

void	x_rotation(float *x, float *y, int *z, fdf *data)
{
	*x = *x;
	*y = (*y - data->center_y) * cos(data->angle->x) - (*z - data->center_z)
		* sin(data->angle->x) + data->center_y;
	*z = (*y - data->center_y) * sin(data->angle->x) + (*z - data->center_z)
		* cos(data->angle->x) + data->center_z;
}

void	y_rotation(float *x, float *y, int *z, fdf *data)
{
	*y = *y;
	*x = (*x - data->center_x) * cos(data->angle->y) - (*z - data->center_z)
		* sin(data->angle->y) + data->center_x;
	*z = (*x - data->center_x) * sin(data->angle->y) + (*z - data->center_z)
		* cos(data->angle->y) + data->center_z;
}

void	rotation(float *x, float *y, int *z, fdf *data)
{
	x_rotation(x, y, z, data);
	y_rotation(x, y, z, data);
	z_rotation(x, y, z, data);
}

void	depth_perception(int *z, fdf *data)
{
	if (*z < 0)
	{
		*z *= (data->depth);
	}
	else if (*z > 0)
	{
		*z *= (data->depth);
	}
}
