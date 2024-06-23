/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:24:03 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 17:05:27 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define DEFAULT_XY_SCALE 40
# define DEFAULT_Z_SCALE  20

# define DEFAULT_COLOR 0xFFFFFF

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_data
{
	const t_point	**orig_points;
	t_point			**points;
	int				rows;
	int				cols;
	int				z_min;
	int				z_max;
}	t_data;

typedef t_point	(*t_operation)(t_point p, double param);

t_data	*construct_data(char *file_path);

void	init_points(t_data *data);

void	apply_operation(t_data *data, t_operation op, double param);
t_point	translate_x(t_point p, double param);
t_point	translate_y(t_point p, double param);
t_point	scale_x(t_point p, double param);
t_point	scale_y(t_point p, double param);
t_point	scale_z(t_point p, double param);
t_point	rotate_x(t_point p, double angle);
t_point	rotate_y(t_point p, double angle);
t_point	rotate_z(t_point p, double angle);

#endif
