/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_points_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:07:39 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/18 19:45:47 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
