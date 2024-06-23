/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:02:42 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 01:48:07 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

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

static void	_set_default_color(t_point *p)
{
	if (p->orig_color == DEFAULT_COLOR_FLAG)
		p->color = 0xFFFFFF;
	else if (p->orig_color != DEFAULT_COLOR_FLAG)
		p->color = p->orig_color;
}

static void	_set_color(t_point *p, t_point *orig_p, t_data *data, int preset)
{
	double	ratio;
	int		bottom;
	int		top;

	if (preset == DEFAULT)
	{
		_set_default_color(p);
		return ;
	}
	_set_preset(&bottom, &top, preset);
	if (data->orig_z_min != data->orig_z_max)
	{
		ratio = (orig_p->z - data->orig_z_min)
			/ (data->orig_z_max - data->orig_z_min);
		p->color = interpolate_color(bottom, top, ratio);
	}
	else if (data->orig_z_min == data->orig_z_max)
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
			_set_color(&data->points[i][j],
				&(((t_point **)data->orig_points)[i][j]), data, preset);
			j++;
		}
		i++;
	}
}
