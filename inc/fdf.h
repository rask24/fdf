/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:59:13 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/15 18:22:21 by reasuke          ###   ########.fr       */
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
# define WIN_HEIGHT 1000

# define NOT_SPECIFIED -1

# define DEFAULT_MAP_SCALE 0.95
# define DEFAULT_Z_SCALE 2
# define SCALE_X 0b001
# define SCALE_Y 0b010
# define SCALE_Z 0b100

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
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		min_val;
	int		max_val;
	t_point	**points;
}	t_map;

typedef struct s_context
{
	t_map	map;
	t_mlx	mlx;
}	t_context;

void	check_args(int argc, char **argv);

void	check_map(char *file_path);

void	extract_map_info(t_map *map, char *file_path);

void	convert_points_to_isometric(t_map *map);

void	render_image(t_map *map, t_mlx *mlx);

void	exit_with_error(char *message);

void	translate_points(t_map *map, int dx, int dy, int dz);
void	scale_points(t_map *map, double scale_factor, int axis_flag);
void	rotate_points_x(t_map *map, double theta);
void	rotate_points_y(t_map *map, double theta);
void	rotate_points_z(t_map *map, double theta);

void	handle_events(t_context *ctx);

void	set_mlx(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

// TODO: delete
void	dev(t_map map);

#endif
