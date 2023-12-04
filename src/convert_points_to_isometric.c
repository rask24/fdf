/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_points_to_isometric.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:28:57 by reasuke           #+#    #+#             */
/*   Updated: 2023/11/27 18:44:19by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	_calc_map_scale(t_map *map)
{
	double	x_rate;
	double	y_rate;

	x_rate = (WIN_WIDTH * DEFAULT_MAP_SCALE * sqrt(2))
		/ (map->width + map->height);
	y_rate = (WIN_HEIGHT * DEFAULT_MAP_SCALE * sqrt(6))
		/ (map->width + map->height);
	if (x_rate < y_rate)
		return (x_rate);
	return (y_rate);
}

void	convert_points_to_isometric(t_map *map)
{
	int		center_map_x;
	int		center_map_y;
	int		center_window_x;
	int		center_window_y;
	double	map_scale;

	map_scale = _calc_map_scale(map);
	center_map_x = (map->width - 1) * map_scale / 2;
	center_map_y = (map->height - 1) * map_scale / 2;
	center_window_x = (WIN_WIDTH - 1) / 2;
	center_window_y = (WIN_HEIGHT - 1) / 2;
	scale_points(map, map_scale, ENLARGE_X | ENLARGE_Y);
	scale_points(map, ENLARGE_RATE_Z, ENLARGE_Z);
	translate_points(map, -center_map_x, -center_map_y, 0);
	rotete_points_z(map, M_PI_4);
	rotete_points_x(map, atan(sqrt(2)));
	translate_points(map, center_window_x, center_window_y, 0);
}
