/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:08:02 by reasuke           #+#    #+#             */
/*   Updated: 2024/07/01 12:30:54 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ctx.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_conf.h"

#include "render_internal.h"

static void	_reset_points(t_ctx *ctx)
{
	reset_image(ctx->mlx_conf);
	clean_points(ctx->data);
	ctx->view_conf->offset_x = 0;
	ctx->view_conf->offset_y = 0;
	init_points(ctx->data);
	init_colors(ctx->data, ctx->view_conf->preset);
}

static void	_put_label(t_ctx *ctx, char *str)
{
	mlx_string_put(ctx->mlx_conf->p_mlx, ctx->mlx_conf->p_win,
		LABEL_X_OFFSET, LABEL_Y_OFFSET, 0xFFFFFF, str);
}

void	prep_render(t_ctx *ctx, bool is_clean)
{
	if (is_clean)
		_reset_points(ctx);
	if (ctx->view_conf->type == ISOMETRIC)
	{
		apply_operation(ctx->data, rotate_z, M_PI_4);
		apply_operation(ctx->data, rotate_x, atan(sqrt(2)));
		render_image(ctx);
		_put_label(ctx, "isometric view");
	}
	else if (ctx->view_conf->type == TOPVIEW)
	{
		render_image(ctx);
		_put_label(ctx, "top view");
	}
	else if (ctx->view_conf->type == OBLIQUE)
	{
		render_image(ctx);
		_put_label(ctx, "oblique view");
	}
	render_instructions(ctx);
}
