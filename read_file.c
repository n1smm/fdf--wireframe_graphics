/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:22:14 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/04 17:34:25 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error_x("get_height fail");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error_x("get_width fail");
	line = get_next_line(fd);
	width = word_counter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, int *z_color, char *line, fdf *data)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		z_color[i] = color_assign(nums[i], z_color[i], data);
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_line(char *file_name, fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error_x("main read fail");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(data->matrix->z_matrix[i], data->matrix->z_color[i], line,
			data);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	data->matrix->z_matrix[i] = NULL;
	data->matrix->z_color[i] = NULL;
	close(fd);
}

void	read_file(char *file_name, fdf *data)
{
	int		i;

	valid_map(data, file_name);
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matrix->has_color = false;
	data->matrix->z_matrix = (int **)malloc((data->height + 1) * sizeof(int *));
	data->matrix->z_color = (int **)malloc((data->height + 1) * sizeof(int *));
	if (!data->matrix->z_matrix || !data->matrix->z_color)
		error_x("matrix alloc fail");
	i = 0;
	while (i < data->height)
	{
		data->matrix->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width
					+ 1));
		data->matrix->z_color[i++] = (int *)malloc(sizeof(int) * (data->width
					+ 1));
		if (!data->matrix->z_matrix[i - 1] || !data->matrix->z_color[i -1])
			error_x("array fail");
	}
	read_line(file_name, data);
}
