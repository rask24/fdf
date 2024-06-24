/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:29:56 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 03:18:51 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ctx.h"
#include "mlx_conf.h"
#include "render.h"

int	handle_mouseup(int button, int x, int y, t_ctx *ctx)
{
	(void)button;
	(void)x;
	(void)y;
	ctx->view_conf->click_x = 0;
	ctx->view_conf->click_y = 0;
	ctx->view_conf->click_btn = 0;
	return (0);
}

int	handle_mousemove(int x, int y, t_ctx *ctx)
{
	if (ctx->view_conf->click_btn == MOUSE_LEFT)
	{
		apply_operation(ctx->data, rotate_y,
			(x - ctx->view_conf->click_x) * 0.002);
		apply_operation(ctx->data, rotate_x,
			-(y - ctx->view_conf->click_y) * 0.002);
		ctx->view_conf->click_x = x;
		ctx->view_conf->click_y = y;
		render(ctx, true, false);
	}
	else if (ctx->view_conf->click_btn == MOUSE_RIGHT)
	{
		ctx->view_conf->offset_x += x - ctx->view_conf->click_x;
		ctx->view_conf->offset_y += y - ctx->view_conf->click_y;
		ctx->view_conf->click_x = x;
		ctx->view_conf->click_y = y;
		render(ctx, true, false);
	}
	return (0);
}

int	handle_mousedown(int button, int x, int y, t_ctx *ctx)
{
	if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
	{
		ctx->view_conf->click_x = x;
		ctx->view_conf->click_y = y;
		ctx->view_conf->click_btn = button;
	}
	else if (button == MOUSE_MIDDLE)
	{
		ctx->view_conf->preset = (ctx->view_conf->preset + 1) % NUM_PRESETS;
		init_colors(ctx->data, ctx->view_conf->preset);
		render(ctx, true, false);
	}
	else if (button == MOUSE_SCROLL_UP)
	{
		apply_operation(ctx->data, scale, 1.1);
		render(ctx, true, false);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		apply_operation(ctx->data, scale, 0.9);
		render(ctx, true, false);
	}
	return (0);
}
