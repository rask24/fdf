/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:23:11 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 21:33:48 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ctx.h"
#include "libft.h"
#include "mlx.h"
#include "render.h"
#include "view_conf.h"

#include "render_internal.h"

static void	_reset_points(t_ctx *ctx)
{
	ft_bzero(ctx->mlx_conf->p_data,
		WIN_WIDTH * WIN_HEIGHT * (ctx->mlx_conf->bits_per_pixel / 8));
	clean_points(ctx->data);
	ctx->view_conf->offset_x = 0;
	ctx->view_conf->offset_y = 0;
	init_points(ctx->data);
	init_colors(ctx->data);
}

void	render(t_ctx *ctx, bool only_render, bool is_clean)
{
	if (only_render)
	{
		ft_bzero(ctx->mlx_conf->p_data,
			WIN_WIDTH * WIN_HEIGHT * (ctx->mlx_conf->bits_per_pixel / 8));
		render_image(ctx);
		return ;
	}
	if (is_clean)
		_reset_points(ctx);
	if (ctx->view_conf->type == ISOMETRIC)
	{
		apply_operation(ctx->data, rotate_z, M_PI_4);
		apply_operation(ctx->data, rotate_x, atan(1 / sqrt(2)));
		render_image(ctx);
		mlx_string_put(ctx->mlx_conf->p_mlx, ctx->mlx_conf->p_win,
			20, 20, 0xFFFFFF, "isometric view");
	}
	else if (ctx->view_conf->type == TOPVIEW)
	{
		render_image(ctx);
		mlx_string_put(ctx->mlx_conf->p_mlx, ctx->mlx_conf->p_win,
			20, 20, 0xFFFFFF, "top view");
	}
}
