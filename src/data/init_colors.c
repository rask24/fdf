/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:02:42 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 18:22:21 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "data.h"
#include "utils.h"

#include "data_internal.h"

void	init_colors(t_data *data)
{
	int		i;
	int		j;
	double	ratio;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->points[i][j].color == DEFAULT_COLOR_FLAG
				&& data->z_max != data->z_min)
			{
				ratio = (double)(data->points[i][j].z - data->z_min)
					/ (data->z_max - data->z_min);
				data->points[i][j].color = interpolate_color(
						DEFAULT_BOTTOM_COLOR, DEFAULT_TOP_COLOR, ratio);
			}
			else if (data->points[i][j].color == DEFAULT_COLOR_FLAG
				&& data->z_max == data->z_min)
				data->points[i][j].color = DEFAULT_BOTTOM_COLOR;
			j++;
		}
		i++;
	}
}
