/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keydown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:41:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 21:48:22 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ctx.h"
#include "data.h"
#include "mlx_conf.h"
#include "render.h"

#include "event_internal.h"

static void	_handle_change_view(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_1)
		ctx->view_conf->type = ISOMETRIC;
	else if (keycode == KEY_2)
		ctx->view_conf->type = TOPVIEW;
	render(ctx, false, true);
}

static void	_handle_translation(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_D)
		ctx->view_conf->offset_x += 10;
	else if (keycode == KEY_A)
		ctx->view_conf->offset_x -= 10;
	else if (keycode == KEY_W)
		ctx->view_conf->offset_y -= 10;
	else if (keycode == KEY_S)
		ctx->view_conf->offset_y += 10;
	render(ctx, true, false);
}

static void	_handle_scale(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_F)
		apply_operation(ctx->data, scale, 1.1);
	else if (keycode == KEY_G)
		apply_operation(ctx->data, scale, 0.9);
	render(ctx, true, false);
}

int	handle_keydown(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_ESCAPE)
		exit_window(ctx);
	else if (keycode == KEY_1 || keycode == KEY_2)
		_handle_change_view(keycode, ctx);
	else if (keycode == KEY_D || keycode == KEY_A
		|| keycode == KEY_W || keycode == KEY_S)
		_handle_translation(keycode, ctx);
	else if (keycode == KEY_F || keycode == KEY_G)
		_handle_scale(keycode, ctx);
	return (0);
}
