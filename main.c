/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:14:49 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/04 15:56:13 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_map(int key, fdf *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img->image);
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	clear_image(data);
	draw(data);
	return (0);
}

void	pre_win_init(fdf *data)
{
	find_peak(data);
	data->win_len = 1000;
	data->win_height = 1000;
}

void	init_draw(fdf *data)
{
	data->zoom = zoom_init(data);
	data->angle->x = 1.0;
	data->angle->y = 0.6;
	data->angle->z = 0.2;
	data->shift_x = data->win_len / 2 - data->width * data->zoom / 2;
	data->shift_y = data->win_height / 2 - data->height * data->zoom / 2;
	data->depth = data->zoom / 10 + 1;
	draw(data);
}

void	free_all(fdf *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
	{
		free(data->matrix->z_matrix[i]);
		free(data->matrix->z_color[i++]);
	}
	free(data->matrix->z_matrix);
	free(data->matrix->z_color);
	free(data->matrix);
	free(data->angle);
	free(data->img);
	free(data->mlx_ptr);
	free(data);
}

int	main(int argc, char **argv)
{
	fdf	*data;

	if (argc != 2)
		return (1);
	data = (fdf *)malloc(sizeof(fdf));
	data->angle = (angle *)malloc(sizeof(angle));
	data->matrix = (matrix *)malloc(sizeof(matrix));
	data->img = (img *)malloc(sizeof(img));
	read_file(argv[1], data);
	pre_win_init(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_len,
			data->win_height, "FDF");
	data->img->image = mlx_new_image(data->mlx_ptr, data->win_len,
			data->win_height);
	data->img->addr = mlx_get_data_addr(data->img->image,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	init_draw(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_map, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, mouse_event, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->image, 0,
		0);
	mlx_loop(data->mlx_ptr);
	free_all(data);
}
