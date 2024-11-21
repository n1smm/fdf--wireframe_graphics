/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:16:21 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/04 15:43:54 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_point(char *line, int z_color)
{
	int		i;
	char	color[9];

	i = 0;
	ft_strlcpy(color, "0xFF", 4);
	while (line[i])
	{
		if (line[i] == ',')
		{
			ft_strlcpy(color, line + i + 1, ft_strlen(line + i));
			z_color = ft_atoi_base(color, 16);
			break ;
		}
		i++;
	}
	return (z_color);
}

int	color_assign(char *nums, int z_color, fdf *data)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (nums[i] == ',')
			break ;
		i++;
	}
	if (i == (int)ft_strlen(nums))
	{
		z_color = 0x00dabc;
		return (z_color);
	}
	z_color = color_point(nums, z_color);
	data->matrix->has_color = true;
	return (z_color);
}

int	color_zgradient(float x, float y, fdf *data)
{
	int	gradient;
	int	color;

	gradient = mod(data->matrix->z_matrix[(int)y][(int)x]) * 20;
	if (mod(data->matrix->z_matrix[(int)y][(int)x]) == 0)
		color = create_trgb(255, 0, 218, 188);
	else if (mod(data->matrix->z_matrix[(int)y][(int)x]) < data->matrix->peak)
		color = create_trgb(255, 207, 0, 174) - gradient;
	else
		color = create_trgb(255, 207, 0, 174);
	return (color);
}

void	color_managment(fdf *data)
{
	if (data->matrix->has_color == true)
	{
		data->color = data->matrix->z_color[(int)data->matrix->y]
		[(int)data->matrix->x];
		data->color1 = data->matrix->z_color[(int)data->matrix->y1]
		[(int)data->matrix->x1];
	}
	else
	{
		data->color = color_zgradient(data->matrix->x, data->matrix->y, data);
		data->color1 = color_zgradient(data->matrix->x1, data->matrix->y1,
				data);
	}
}

int	interpolate_color(int color1, int color2, float ratio)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)(get_t(color1) * (1 - ratio) + get_t(color2) * ratio);
	r = (int)(get_r(color1) * (1 - ratio) + get_r(color2) * ratio);
	g = (int)(get_g(color1) * (1 - ratio) + get_g(color2) * ratio);
	b = (int)(get_b(color1) * (1 - ratio) + get_b(color2) * ratio);
	return (create_trgb(t, r, g, b));
}
