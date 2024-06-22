/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:40:43 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 16:04:27 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "utils.h"

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

static void	_centering_points(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			data->points[i][j].x -= (data->cols - 1.0) / 2.0;
			data->points[i][j].y -= (data->rows - 1.0) / 2.0;
			j++;
		}
		i++;
	}
}

void	init_points(t_data *data)
{
	data->points = _alloc_points(data->rows, data->cols);
	_copy_orig_points(data);
	_centering_points(data);
}
