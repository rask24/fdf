/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratate_points_y.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:07:39 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/18 19:46:20 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
