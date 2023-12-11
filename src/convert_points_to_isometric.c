/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_points_to_isometric.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:28:57 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/11 13:24:11 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	_calc_map_scale(t_map *map)
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

// static double	_calc_z_scale(t_map *map)
// {
// 	int		max;
// 	int		x;
// 	int		y;
// 	double	tmp;

// 	max = INT_MIN;
// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			tmp = sin(atan(sqrt(2))) * map->points[y][x].y
// 				+ cos(atan(sqrt(2))) * map->points[y][x].z;
// 			ft_chmax(&max, tmp);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (max);
// }

void	convert_points_to_isometric(t_map *map)
{
	int		center_map_x;
	int		center_map_y;
	double	map_scale;

	map_scale = _calc_map_scale(map);
	center_map_x = (map->width - 1) * map_scale / 2;
	center_map_y = (map->height - 1) * map_scale / 2;
	scale_points(map, map_scale, SCALE_X | SCALE_Y);
	scale_points(map, DEFAULT_Z_SCALE, SCALE_Z);
	translate_points(map, -center_map_x, -center_map_y, 0);
	rotete_points_z(map, M_PI_4);
	rotete_points_x(map, atan(sqrt(2)));
}
