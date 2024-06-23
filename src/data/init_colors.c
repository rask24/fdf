/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:02:42 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 01:01:58 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include "data.h"
#include "utils.h"
#include "view_conf.h"

#include "data_internal.h"

static void	_set_preset(int *bottom, int *top, t_preset preset)
{
	if (preset == DARK)
	{
		*bottom = DARK_BOTTOM_COLOR;
		*top = DARK_TOP_COLOR;
	}
	else if (preset == TROPICAL)
	{
		*bottom = TROPICAL_BOTTOM_COLOR;
		*top = TROPICAL_TOP_COLOR;
	}
	else if (preset == PASTEL)
	{
		*bottom = PASTEL_BOTTOM_COLOR;
		*top = PASTEL_TOP_COLOR;
	}
	else
	{
		*bottom = 0xFFFFFF;
		*top = 0xFFFFFF;
	}
}

static void	_set_color(t_point *p, t_data *data, int preset)
{
	double	ratio;
	int		bottom;
	int		top;

	_set_preset(&bottom, &top, preset);
	if (p->color == DEFAULT_COLOR_FLAG && data->z_min != data->z_max)
	{
		ratio = (p->z - data->z_min) / (data->z_max - data->z_min);
		p->color = interpolate_color(bottom, top, ratio);
	}
	else if (p->color == DEFAULT_COLOR_FLAG && data->z_min == data->z_max)
		p->color = bottom;
}

void	init_colors(t_data *data, int preset)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			_set_color(&data->points[i][j], data, preset);
			j++;
		}
		i++;
	}
}
