/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keydown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:41:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/07/02 00:08:36 by reasuke          ###   ########.fr       */
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
	else if (keycode == KEY_3)
		ctx->view_conf->type = OBLIQUE;
	else if (keycode == KEY_4)
		ctx->view_conf->type = PERSPECTIVE;
	prep_render(ctx, true);
}

static void	_handle_translation(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_D)
		ctx->view_conf->offset_x += TRANSLATION_STEP;
	else if (keycode == KEY_A)
		ctx->view_conf->offset_x -= TRANSLATION_STEP;
	else if (keycode == KEY_W)
		ctx->view_conf->offset_y -= TRANSLATION_STEP;
	else if (keycode == KEY_S)
		ctx->view_conf->offset_y += TRANSLATION_STEP;
	render(ctx);
}

static void	_handle_scale(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_F)
		apply_operation(ctx->data, scale, 1 + SCALE_STEP);
	else if (keycode == KEY_G)
		apply_operation(ctx->data, scale, 1 - SCALE_STEP);
	render(ctx);
}

static void	_handle_rotation(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_Q)
		apply_operation(ctx->data, rotate_y, -ROTATION_STEP_KEY);
	else if (keycode == KEY_E)
		apply_operation(ctx->data, rotate_y, ROTATION_STEP_KEY);
	else if (keycode == KEY_R)
		apply_operation(ctx->data, rotate_x, ROTATION_STEP_KEY);
	else if (keycode == KEY_V)
		apply_operation(ctx->data, rotate_x, -ROTATION_STEP_KEY);
	else if (keycode == KEY_Z)
		apply_operation(ctx->data, rotate_z, -ROTATION_STEP_KEY);
	else if (keycode == KEY_C)
		apply_operation(ctx->data, rotate_z, ROTATION_STEP_KEY);
	render(ctx);
}

int	handle_keydown(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_ESCAPE)
		exit_window(ctx);
	else if (KEY_1 <= keycode && keycode <= KEY_4)
		_handle_change_view(keycode, ctx);
	else if (keycode == KEY_D || keycode == KEY_A
		|| keycode == KEY_W || keycode == KEY_S)
		_handle_translation(keycode, ctx);
	else if (keycode == KEY_F || keycode == KEY_G)
		_handle_scale(keycode, ctx);
	else if (keycode == KEY_Q || keycode == KEY_E
		|| keycode == KEY_R || keycode == KEY_V
		|| keycode == KEY_Z || keycode == KEY_C)
		_handle_rotation(keycode, ctx);
	else if (keycode == KEY_X)
	{
		ctx->view_conf->preset = (ctx->view_conf->preset + 1) % NUM_PRESETS;
		init_colors(ctx->data, ctx->view_conf->preset);
		render(ctx);
	}
	else if (keycode == KEY_T)
	{
		ctx->view_conf->show_instr = !ctx->view_conf->show_instr;
		render(ctx);
	}
	return (0);
}
