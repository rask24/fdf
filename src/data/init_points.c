/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:40:43 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/26 01:57:38 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "libft.h"
#include "mlx_conf.h"
#include "utils.h"

#include "data_internal.h"

static t_point	**_alloc_points(int row, int col)
{
	t_point	**points;
	int		i;

	points = malloc(sizeof(t_point *) * row);
	if (points == NULL)
		error_exit(strerror(errno));
	i = 0;
	while (i < row)
	{
		points[i] = malloc(sizeof(t_point) * col);
		if (points[i] == NULL)
			error_exit(strerror(errno));
		i++;
	}
	return (points);
}

static void	_copy_orig_points(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->rows)
	{
		ft_memcpy(data->points[i], data->orig_points[i],
			sizeof(t_point) * data->cols);
		i++;
	}
}

static double	_calc_xy_scale(t_data *data)
{
	double	x_scale;
	double	y_scale;

	x_scale = (double)(WIN_WIDTH - 2 * WIN_MARGIN) / data->cols;
	y_scale = (double)(WIN_HEIGHT - 2 * WIN_MARGIN) / data->rows;
	if (x_scale < y_scale)
		return (x_scale);
	else
		return (y_scale);
}

static double	_calc_z_scale(t_data *data, double xy_scale)
{
	double	z_range;

	z_range = data->orig_z_max - data->orig_z_min;
	if (z_range * xy_scale < Z_RANGE_THRESHOLD)
		return (xy_scale / 2.0);
	return (Z_RANGE_THRESHOLD / z_range);
}

void	init_points(t_data *data)
{
	double	xy_scale;
	double	z_scale;

	data->points = _alloc_points(data->rows, data->cols);
	_copy_orig_points(data);
	apply_operation(data, translate_x, -(data->cols - 1.0) / 2.0);
	apply_operation(data, translate_y, -(data->rows - 1.0) / 2.0);
	xy_scale = _calc_xy_scale(data);
	z_scale = _calc_z_scale(data, xy_scale);
	apply_operation(data, scale_x, xy_scale);
	apply_operation(data, scale_y, xy_scale);
	apply_operation(data, scale_z, _calc_z_scale(data, z_scale));
}
