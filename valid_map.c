/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:18:00 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/04 17:53:42 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	valid_map(fdf *data, char *file_name)
{
	int	fd;
	int	flag;

	flag = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd >= 0)
		flag = 1;
	if (ft_strnstr(file_name, ".fdf", ft_strlen(file_name)) != 0 && flag == 1)
		return ;
	free(data->angle);
	free(data->matrix);
	free(data->img);
	free(data);
	perror("file inxestent or invalid");
	exit(EXIT_FAILURE);
}
