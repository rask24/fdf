/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:07:39 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/18 17:53:09 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_points(t_map *map, double dx, double dy, double dz)
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

void	scale_points(t_map *map, double scale_factor, int axis_flag)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (axis_flag & SCALE_X)
				map->points[y][x].x *= scale_factor;
			if (axis_flag & SCALE_Y)
				map->points[y][x].y *= scale_factor;
			if (axis_flag & SCALE_Z)
				map->points[y][x].z *= scale_factor;
			x++;
		}
		y++;
	}
}

void	rotate_points_x(t_map *map, double theta)
{
	int		x;
	int		y;
	double	tmp_y;
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

void	rotate_points_y(t_map *map, double theta)
{
	int		x;
	int		y;
	double	tmp_x;
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
				- sin_theta * map->points[y][x].z;
			map->points[y][x].z = sin_theta * tmp_x
				+ cos_theta * map->points[y][x].z;
			x++;
		}
		y++;
	}
}

void	rotate_points_z(t_map *map, double theta)
{
	int		x;
	int		y;
	double	tmp_x;
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
