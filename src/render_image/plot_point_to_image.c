/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_point_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:09:02 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/20 15:39:54 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_point_to_image(t_ctx *ctx, int x, int y, int color)
{
	int		center_window_x;
	int		center_window_y;
	int		position_x;
	int		position_y;

	center_window_x = (WIN_WIDTH - 1) / 2;
	center_window_y = (WIN_HEIGHT - 1) / 2;
	position_x = x + center_window_x + ctx->offset_x;
	position_y = y + center_window_y + ctx->offset_y;
	my_mlx_pixel_put(ctx, position_x, position_y, color);
}
