/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:59:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 21:25:12 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "mlx.h"

void	plot_pixel(t_ctx *ctx, int x, int y, int color)
{
	char	*dst;
	int		win_x;
	int		win_y;

	win_x = x + (WIN_WIDTH - 1) / 2 + ctx->view_conf->offset_x;
	win_y = y + (WIN_HEIGHT - 1) / 2 + ctx->view_conf->offset_y;
	if (win_x < 0 || win_x >= WIN_WIDTH || win_y < 0 || win_y >= WIN_HEIGHT)
		return ;
	dst = ctx->mlx_conf->p_data + (win_y * ctx->mlx_conf->line_length
			+ win_x * (ctx->mlx_conf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
