/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:07:39 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/18 19:44:41 by reasuke          ###   ########.fr       */
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
