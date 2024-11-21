/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:08:39 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/04 15:44:28 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_nbr(const char *nptr, int base, int *count)
{
	long	result;
	int		value;

	result = 0;
	if (base == 16 && nptr[*count] == '0' && (nptr[*count + 1] == 'x'
			|| nptr[*count + 1] == 'X'))
		*count += 2;
	while (ft_isdigit(nptr[*count]) || ft_isalpha(nptr[*count]))
	{
		if (ft_isdigit(nptr[*count]))
			value = nptr[*count] - '0';
		else if (ft_isalpha(nptr[*count]))
			value = ft_toupper(nptr[*count]) - 'A' + 10;
		result = result * base + value;
		(*count)++;
	}
	return (result);
}

int	ft_atoi_base(const char *nptr, int base)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 0;
	while ((nptr[count] > 8 && nptr[count] < 14) || nptr[count] == 32)
		count++;
	if (nptr[count] == '+')
		count++;
	else if (nptr[count] == '-')
	{
		sign = 1;
		count++;
	}
	result = get_nbr(nptr, base, &count);
	if (sign == 1)
		result = -result;
	return ((int)result);
}

void	my_pixel_put(fdf *data, int x, int y, int color)
{
	int		offset;
	char	*dest;

	offset = (y * data->img->line_length + x * (data->img->bits_per_pixel / 8));
	dest = data->img->addr + offset;
	*(unsigned int *)dest = color;
}

void	clear_image(fdf *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= 1000)
	{
		x = 0;
		while (x <= 1000)
		{
			my_pixel_put(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->image, 0,
		0);
}

int	zoom_init(fdf *data)
{
	int	zoom;

	if (data->height >= data->win_height - 100 || data->width >= data->win_len
		- 100)
		zoom = 0;
	else if (data->width >= data->height)
		zoom = (data->win_len - 100) / data->width;
	else
		zoom = (data->win_height - 100) / data->height;
	return (zoom);
}
