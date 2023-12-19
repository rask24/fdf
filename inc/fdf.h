/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:59:13 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/19 17:56:05reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include "libft.h"
# include "mlx.h"

# include "mlx_config.h"

# define WIN_WIDTH  1200
# define WIN_HEIGHT 800

# define NO_COLOR_SPEC -1
# define DEFAULT_COLOR_TOP    0xFFFFFF
# define DEFAULT_COLOR_BOTTOM 0x292929

# define DEFAULT_MAP_SCALE 0.95
# define DEFAULT_Z_SCALE 2
# define SCALE_X 0b001
# define SCALE_Y 0b010
# define SCALE_Z 0b100

# define TRANSLATE_STEP 10
# define ROTATE_STEP 0.05
# define SCALE_STEP 0.1

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**points;
}	t_map;

typedef struct s_context
{
	t_map	map;
	t_mlx	mlx;
}	t_context;

typedef struct s_line_conf
{
	bool	steep;
	int		dx;
	int		dy;
	int		error;
	int		x;
	int		y;
	int		step_y;
	int		color_start;
	int		color_end;
}	t_line_conf;

typedef struct s_xw
{
	bool	steep;
	double	dx;
	double	dy;
	double	gradient;
	double	x_pxl1;
	double	y_pxl1;
	double	x_pxl2;
	double	y_pxl2;
	double	intery;
	int		color_start;
	int		color_end;
}	t_xw;

void	check_args(int argc, char **argv);

void	check_map(char *file_path);

void	extract_map_info(t_map *map, char *file_path);

void	convert_points_to_isometric(t_map *map);

void	plot_line(t_point p0, t_point p1, t_mlx *mlx);

void	render_image(t_map *map, t_mlx *mlx);

void	exit_with_error(char *message);

void	translate_points(t_map *map, double dx, double dy, double dz);
void	scale_points(t_map *map, double scale_factor, int axis_flag);
void	rotate_points_x(t_map *map, double theta);
void	rotate_points_y(t_map *map, double theta);
void	rotate_points_z(t_map *map, double theta);

void	handle_events(t_context *ctx);
int		handle_keydown(int keycode, void *param);
int		exit_window(void);

int		color_gradient(int color1, int color2, double ratio);

void	set_mlx(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

// TODO: delete
void	dev(t_map map);

#endif
