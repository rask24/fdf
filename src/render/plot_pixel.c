/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:59:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 00:44:01 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "mlx.h"

void	plot_pixel(t_ctx *ctx, int win_x, int win_y, int color)
{
	char	*dst;

	if (win_x < 0 || win_x >= WIN_WIDTH || win_y < 0 || win_y >= WIN_HEIGHT)
		return ;
	dst = ctx->mlx_conf->p_data + (win_y * ctx->mlx_conf->line_length
			+ win_x * (ctx->mlx_conf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
