/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keydown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:41:34 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/06 19:55:46 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <X11/keysym.h>

#include "ctx.h"
#include "data.h"
#include "mlx_conf.h"
#include "render.h"

#include "event_internal.h"

static void	_handle_change_view(int keycode, t_ctx *ctx)
{
	if (keycode == XK_1)
		ctx->view_conf->type = ISOMETRIC;
	else if (keycode == XK_2)
		ctx->view_conf->type = TOPVIEW;
	else if (keycode == XK_3)
		ctx->view_conf->type = OBLIQUE;
	else if (keycode == XK_4)
		ctx->view_conf->type = PERSPECTIVE;
	prep_render(ctx, true);
}

static void	_handle_translation(int keycode, t_ctx *ctx)
{
	if (keycode == XK_d)
		ctx->view_conf->offset_x += TRANSLATION_STEP;
	else if (keycode == XK_a)
		ctx->view_conf->offset_x -= TRANSLATION_STEP;
	else if (keycode == XK_w)
		ctx->view_conf->offset_y -= TRANSLATION_STEP;
	else if (keycode == XK_s)
		ctx->view_conf->offset_y += TRANSLATION_STEP;
	render(ctx);
}

static void	_handle_scale(int keycode, t_ctx *ctx)
{
	if (keycode == XK_f)
		apply_operation(ctx->data, scale, 1 + SCALE_STEP);
	else if (keycode == XK_g)
		apply_operation(ctx->data, scale, 1 - SCALE_STEP);
	render(ctx);
}

static void	_handle_rotation(int keycode, t_ctx *ctx)
{
	if (keycode == XK_q)
		apply_operation(ctx->data, rotate_y, -ROTATION_STEP_KEY);
	else if (keycode == XK_e)
		apply_operation(ctx->data, rotate_y, ROTATION_STEP_KEY);
	else if (keycode == XK_r)
		apply_operation(ctx->data, rotate_x, ROTATION_STEP_KEY);
	else if (keycode == XK_v)
		apply_operation(ctx->data, rotate_x, -ROTATION_STEP_KEY);
	else if (keycode == XK_z)
		apply_operation(ctx->data, rotate_z, -ROTATION_STEP_KEY);
	else if (keycode == XK_c)
		apply_operation(ctx->data, rotate_z, ROTATION_STEP_KEY);
	render(ctx);
}

int	handle_keydown(int keycode, t_ctx *ctx)
{
	if (keycode == XK_Escape)
		exit_window(ctx);
	else if (XK_1 <= keycode && keycode <= XK_4)
		_handle_change_view(keycode, ctx);
	else if (keycode == XK_d || keycode == XK_a
		|| keycode == XK_w || keycode == XK_s)
		_handle_translation(keycode, ctx);
	else if (keycode == XK_f || keycode == XK_g)
		_handle_scale(keycode, ctx);
	else if (keycode == XK_q || keycode == XK_e
		|| keycode == XK_r || keycode == XK_v
		|| keycode == XK_z || keycode == XK_c)
		_handle_rotation(keycode, ctx);
	else if (keycode == XK_x)
	{
		ctx->view_conf->preset = (ctx->view_conf->preset + 1) % NUM_PRESETS;
		init_colors(ctx->data, ctx->view_conf->preset);
		render(ctx);
	}
	else if (keycode == XK_t)
	{
		ctx->view_conf->show_instr = !ctx->view_conf->show_instr;
		render(ctx);
	}
	return (0);
}
