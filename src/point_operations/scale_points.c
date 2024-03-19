/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:07:39 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/18 19:45:13 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
