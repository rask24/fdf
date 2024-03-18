/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:59:13 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/23 18:22:36 by reasuke          ###   ########.fr       */
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
# define DEFAULT_COLOR_BOTTOM 0x555555

# define DEFAULT_MAP_SCALE 0.95
# define DEFAULT_Z_SCALE 20
# define SCALE_X 0b001
# define SCALE_Y 0b010
# define SCALE_Z 0b100

# define TRANSLATE_STEP 10
# define ROTATE_STEP 0.05
# define SCALE_STEP 0.1

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_ctx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map_witdh;
	int		map_height;
	t_point	**points;
	int		offset_x;
	int		offset_y;
}	t_ctx;

typedef struct s_line_conf
{
	bool	steep;
	double	gradient;
	double	x_pxl1;
	double	y_pxl1;
	double	x_pxl2;
	double	y_pxl2;
	double	intery;
	int		color_start;
	int		color_end;
}	t_line_conf;

void	check_args(int argc, char **argv);

void	check_map(char *file_path);

void	extract_map_info(t_ctx *ctx, char *file_path);

void	convert_points_to_isometric(t_ctx *ctx);

void	plot_line(t_point p0, t_point p1, t_ctx *ctx);

void	render_image(t_ctx *ctx);

void	plot_point_to_image(t_ctx *ctx, int x, int y, int color);
double	calc_ratio(t_point p0, t_point p1, double x, double y);
double	fpart(double x);
double	rfpart(double x);

void	exit_with_error(char *message);

void	translate_points(t_ctx *ctx, double dx, double dy, double dz);
void	scale_points(t_ctx *ctx, double scale_factor, int axis_flag);
void	rotate_points_x(t_ctx *ctx, double theta);
void	rotate_points_y(t_ctx *ctx, double theta);
void	rotate_points_z(t_ctx *ctx, double theta);

void	handle_events(t_ctx *ctx);
int		handle_keydown(int keycode, void *param);
int		exit_window(void);

int		color_gradient(int color1, int color2, double ratio);

void	set_mlx(t_ctx *ctx);
void	my_mlx_pixel_put(t_ctx *mlx, int x, int y, int color);

// TODO: delete
void	dev(t_ctx ctx);

#endif
