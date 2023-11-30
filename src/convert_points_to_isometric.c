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

void	_translate_points(t_map *map, int dx, int dy, int dz)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y][x].x += dx;
			map->points[y][x].y += dy;
			map->points[y][x].z += dz;
			x++;
		}
		y++;
	}
}

void	_enlarge_map(t_map *map, int rate, int axis_flag)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (axis_flag & ENLARGE_X)
				map->points[y][x].x *= rate;
			if (axis_flag & ENLARGE_Y)
				map->points[y][x].y *= rate;
			if (axis_flag & ENLARGE_Z)
				map->points[y][x].z *= rate;
			x++;
		}
		y++;
	}
}

void	_rotete_x_axis(t_map *map, double theta)
{
	int		x;
	int		y;
	int		tmp_y;
	double	cos_theta;
	double	sin_theta;

	cos_theta = cos(theta);
	sin_theta = sin(theta);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			tmp_y = map->points[y][x].y;
			map->points[y][x].y = cos_theta * tmp_y
				- sin_theta * map->points[y][x].z;
			map->points[y][x].z = sin_theta * tmp_y
				+ cos_theta * map->points[y][x].z;
			x++;
		}
		y++;
	}
}

void	_rotete_z_axis(t_map *map, double theta)
{
	int		x;
	int		y;
	int		tmp_x;
	double	cos_theta;
	double	sin_theta;

	cos_theta = cos(theta);
	sin_theta = sin(theta);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			tmp_x = map->points[y][x].x;
			map->points[y][x].x = cos_theta * tmp_x
				- sin_theta * map->points[y][x].y;
			map->points[y][x].y = sin_theta * tmp_x
				+ cos_theta * map->points[y][x].y;
			x++;
		}
		y++;
	}
}

void	convert_points_to_isometric(t_map *map)
{
	int	center_map_x;
	int	center_map_y;
	int	center_window_x;
	int	center_window_y;

	center_map_x = (map->width - 1) * ENLARGE_RATE_XY / 2;
	center_map_y = (map->height - 1) * ENLARGE_RATE_XY / 2;
	center_window_x = (WIN_WIDTH - 1) / 2;
	center_window_y = (WIN_HEIGHT - 1) / 2;
	_enlarge_map(map, ENLARGE_RATE_XY, ENLARGE_X | ENLARGE_Y);
	_enlarge_map(map, ENLARGE_RATE_Z, ENLARGE_Z);
	_translate_points(map, -center_map_x, -center_map_y, 0);
	_rotete_z_axis(map, M_PI_4);
	_rotete_x_axis(map, atan(sqrt(2)));
	_translate_points(map, center_window_x, center_window_y, 0);
}
