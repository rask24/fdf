/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:40:43 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 15:00:37 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "libft.h"
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

void	init_points(t_data *data)
{
	data->points = _alloc_points(data->rows, data->cols);
	_copy_orig_points(data);
	apply_operation(data, translate_x, -(data->cols - 1.0) / 2.0);
	apply_operation(data, translate_y, -(data->rows - 1.0) / 2.0);
	apply_operation(data, scale_x, DEFAULT_XY_SCALE);
	apply_operation(data, scale_y, DEFAULT_XY_SCALE);
	apply_operation(data, scale_z, DEFAULT_Z_SCALE);
}
