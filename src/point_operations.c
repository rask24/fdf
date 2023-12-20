/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:07:39 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/20 15:31:49 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_points(t_ctx *ctx, double dx, double dy, double dz)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->map_height)
	{
		x = 0;
		while (x < ctx->map_witdh)
		{
			ctx->points[y][x].x += dx;
			ctx->points[y][x].y += dy;
			ctx->points[y][x].z += dz;
			x++;
		}
		y++;
	}
}

void	scale_points(t_ctx *ctx, double scale_factor, int axis_flag)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->map_height)
	{
		x = 0;
		while (x < ctx->map_witdh)
		{
			if (axis_flag & SCALE_X)
				ctx->points[y][x].x *= scale_factor;
			if (axis_flag & SCALE_Y)
				ctx->points[y][x].y *= scale_factor;
			if (axis_flag & SCALE_Z)
				ctx->points[y][x].z *= scale_factor;
			x++;
		}
		y++;
	}
}

void	rotate_points_x(t_ctx *ctx, double theta)
{
	int		x;
	int		y;
	double	tmp_y;
	double	cos_theta;
	double	sin_theta;

	cos_theta = cos(theta);
	sin_theta = sin(theta);
	y = 0;
	while (y < ctx->map_height)
	{
		x = 0;
		while (x < ctx->map_witdh)
		{
			tmp_y = ctx->points[y][x].y;
			ctx->points[y][x].y = cos_theta * tmp_y
				- sin_theta * ctx->points[y][x].z;
			ctx->points[y][x].z = sin_theta * tmp_y
				+ cos_theta * ctx->points[y][x].z;
			x++;
		}
		y++;
	}
}

void	rotate_points_y(t_ctx *ctx, double theta)
{
	int		x;
	int		y;
	double	tmp_x;
	double	cos_theta;
	double	sin_theta;

	cos_theta = cos(theta);
	sin_theta = sin(theta);
	y = 0;
	while (y < ctx->map_height)
	{
		x = 0;
		while (x < ctx->map_witdh)
		{
			tmp_x = ctx->points[y][x].x;
			ctx->points[y][x].x = cos_theta * tmp_x
				- sin_theta * ctx->points[y][x].z;
			ctx->points[y][x].z = sin_theta * tmp_x
				+ cos_theta * ctx->points[y][x].z;
			x++;
		}
		y++;
	}
}

void	rotate_points_z(t_ctx *ctx, double theta)
{
	int		x;
	int		y;
	double	tmp_x;
	double	cos_theta;
	double	sin_theta;

	cos_theta = cos(theta);
	sin_theta = sin(theta);
	y = 0;
	while (y < ctx->map_height)
	{
		x = 0;
		while (x < ctx->map_witdh)
		{
			tmp_x = ctx->points[y][x].x;
			ctx->points[y][x].x = cos_theta * tmp_x
				- sin_theta * ctx->points[y][x].y;
			ctx->points[y][x].y = sin_theta * tmp_x
				+ cos_theta * ctx->points[y][x].y;
			x++;
		}
		y++;
	}
}
