/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_points_to_isometric.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:28:57 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/20 15:17:40 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	_calc_map_scale(t_ctx *ctx)
{
	double	x_rate;
	double	y_rate;

	x_rate = (WIN_WIDTH * DEFAULT_MAP_SCALE * sqrt(2))
		/ (ctx->width + ctx->height);
	y_rate = (WIN_HEIGHT * DEFAULT_MAP_SCALE * sqrt(6))
		/ (ctx->width + ctx->height);
	if (x_rate < y_rate)
		return (x_rate);
	return (y_rate);
}

// static double	_calc_z_scale(t_map *ctx)
// {
// 	int		max;
// 	int		x;
// 	int		y;
// 	double	tmp;

// 	max = INT_MIN;
// 	y = 0;
// 	while (y < ctx->height)
// 	{
// 		x = 0;
// 		while (x < ctx->width)
// 		{
// 			tmp = sin(atan(sqrt(2))) * ctx->points[y][x].y
// 				+ cos(atan(sqrt(2))) * ctx->points[y][x].z;
// 			ft_chmax(&max, tmp);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (max);
// }

void	convert_points_to_isometric(t_ctx *ctx)
{
	int		center_map_x;
	int		center_map_y;
	double	map_scale;

	map_scale = _calc_map_scale(ctx);
	center_map_x = (ctx->width - 1) * map_scale / 2;
	center_map_y = (ctx->height - 1) * map_scale / 2;
	scale_points(ctx, map_scale, SCALE_X | SCALE_Y);
	scale_points(ctx, DEFAULT_Z_SCALE, SCALE_Z);
	translate_points(ctx, -center_map_x, -center_map_y, 0);
	rotate_points_z(ctx, M_PI_4);
	rotate_points_x(ctx, atan(sqrt(2)));
}
