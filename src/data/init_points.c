/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:40:43 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 16:41:43 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
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
	int		j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			data->points[i][j] = data->orig_points[i][j];
			j++;
		}
		i++;
	}
}

static void	_init_colors(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->points[i][j].color == DEFAULT_COLOR_FLAG)
				data->points[i][j].color = DEFAULT_COLOR;
			j++;
		}
		i++;
	}
}

void	init_points(t_data *data)
{
	data->points = _alloc_points(data->rows, data->cols);
	_copy_orig_points(data);
	_init_colors(data);
	apply_operation(data, translate_x, -(data->cols - 1.0) / 2.0);
	apply_operation(data, translate_y, -(data->rows - 1.0) / 2.0);
	apply_operation(data, scale_x, DEFAULT_XY_SCALE);
	apply_operation(data, scale_y, DEFAULT_XY_SCALE);
	apply_operation(data, scale_z, DEFAULT_Z_SCALE);
}
