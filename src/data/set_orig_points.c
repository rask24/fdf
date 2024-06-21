/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_orig_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:51:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 03:54:21 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "libft.h"
#include "utils.h"

#include "data_internal.h"

static const t_point	**_alloc_orig_points(int row, int col)
{
	const t_point	**points;
	int				i;

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

static void	_set_z_and_color(t_data *data, char *str, int row)
{
	int		j;
	char	*endptr;

	j = 0;
	while (j < data->cols)
	{
		while (ft_isblank(*str))
			str++;
		((t_point **)data->orig_points)[row][j].z = ft_strtol(str, &endptr, 10);
		if (*endptr == ',')
		{
			str = endptr + 1;
			((t_point **)data->orig_points)[row][j].color
				= ft_strtol(str, &endptr, 16);
		}
		else
			((t_point **)data->orig_points)[row][j].color = DEFAULT_COLOR_FLAG;
		str = endptr;
		j++;
	}
}

void	set_orig_points(t_data *data, char **map)
{
	int	i;
	int	j;

	data->orig_points = _alloc_orig_points(data->rows, data->cols);
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			((t_point **)data->orig_points)[i][j].x = j;
			((t_point **)data->orig_points)[i][j].y = data->rows - i - 1;
			j++;
		}
		_set_z_and_color(data, map[i], i);
		i++;
	}
}
