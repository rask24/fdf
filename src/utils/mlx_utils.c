/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:24:29 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/20 15:18:25 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_mlx(t_ctx *ctx)
{
	ctx->mlx_ptr = mlx_init();
	ctx->win_ptr = mlx_new_window(ctx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	ctx->img_ptr = mlx_new_image(ctx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ctx->data_addr = mlx_get_data_addr(ctx->img_ptr,
			&ctx->bits_per_pixel, &ctx->line_length, &ctx->endian);
}

void	my_mlx_pixel_put(t_ctx *ctx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || WIN_WIDTH <= x || y < 0 || WIN_HEIGHT <= y)
		return ;
	dst = ctx->data_addr
		+ (y * ctx->line_length + x * (ctx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
