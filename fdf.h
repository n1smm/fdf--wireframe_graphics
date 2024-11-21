/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:38 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/04 17:33:33 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./final_libft/libft.h"
# include "./final_printf/ft_printf.h"
# include "./gnl_finished/get_next_line.h"
# include "./mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
	float	x;
	float	y;
	float	z;
}			angle;

typedef struct
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		xx;
	int		xx1;
	int		yy;
	int		yy1;

	int		**z_matrix;
	int		**z_color;
	int		peak;
	bool	has_color;
}			matrix;

typedef struct
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
}			img;

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		color1;
	int		shift_x;
	int		shift_y;
	int		center_x;
	int		center_y;
	int		center_z;
	int		depth;
	int		win_len;
	int		win_height;

	void	*mlx_ptr;
	void	*win_ptr;
	angle	*angle;
	matrix	*matrix;
	img		*img;
}			fdf;

/* main */
int			deal_key(int key, fdf *data);
/* read_file */
int			get_height(char *file_name);
int			get_width(char *file_name);
void		fill_matrix(int *z_line, int *z_color, char *line, fdf *data);
void		read_file(char *file_name, fdf *data);
/* draw */
void		draw_mods(fdf *data);
void		draw(fdf *data);
float		mod(float i);
void		find_peak(fdf *data);
void		error_x(char *msg);
/* draw_utils */
void		dda_algo(fdf *data);
void		draw_zoom(fdf *data);
void		draw_shift(fdf *data);
/* utils */
int			ft_atoi_base(const char *nptr, int base);
void		my_pixel_put(fdf *data, int x, int y, int color);
void		clear_image(fdf *data);
int			zoom_init(fdf *data);
/* color_managment */
int			color_assign(char *nums, int z_color, fdf *data);
int			interpolate_color(int color1, int color2, float ratio);
void		color_managment(fdf *data);
/* color_creation */
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
/* rotation */
void		rotation(float *x, float *y, int *z, fdf *data);
void		depth_perception(int *z, fdf *data);
/* hook_events */
int			mouse_event(fdf *data);
void		shift_keys(int key, fdf *data);
void		perspective_zoom(int key, fdf *data);
void		rotate_depth(int key, fdf *data);
void		instructions_put(fdf *data);
/* valid_map */
void valid_map(fdf *data, char *file_name);
#endif
