/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:00:48 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/20 15:20:42 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	_connect_points_grid_image(t_ctx *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->height)
	{
		j = 0;
		while (j < ctx->width - 1)
		{
			plot_line(ctx->points[i][j], ctx->points[i][j + 1], ctx);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < ctx->width)
	{
		j = 0;
		while (j < ctx->height - 1)
		{
			plot_line(ctx->points[j][i], ctx->points[j + 1][i], ctx);
			j++;
		}
		i++;
	}
}

void	render_image(t_ctx *ctx)
{
	_connect_points_grid_image(ctx);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, ctx->img_ptr, 0, 0);
}
