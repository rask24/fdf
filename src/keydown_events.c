/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keydown_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:16:41 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/20 15:27:30 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_handle_translation(int keycode, t_ctx *ctx)
{
	ft_bzero(ctx->data_addr,
		WIN_HEIGHT * WIN_WIDTH * (ctx->bits_per_pixel / 8));
	if (keycode == KEY_S)
		translate_points(ctx, 0, TRANSLATE_STEP, 0);
	else if (keycode == KEY_W)
		translate_points(ctx, 0, -TRANSLATE_STEP, 0);
	else if (keycode == KEY_A)
		translate_points(ctx, -TRANSLATE_STEP, 0, 0);
	else if (keycode == KEY_D)
		translate_points(ctx, TRANSLATE_STEP, 0, 0);
	render_image(ctx);
}

static void	_handle_scale(int keycode, t_ctx *ctx)
{
	ft_bzero(ctx->data_addr,
		WIN_HEIGHT * WIN_WIDTH * (ctx->bits_per_pixel / 8));
	if (keycode == KEY_PLUS)
		scale_points(ctx, 1 + SCALE_STEP, SCALE_X | SCALE_Y);
	else if (keycode == KEY_MINUS)
		scale_points(ctx, 1 - SCALE_STEP, SCALE_X | SCALE_Y);
	render_image(ctx);
}

static void	_handle_rotation(int keycode, t_ctx *ctx)
{
	ft_bzero(ctx->data_addr,
		WIN_HEIGHT * WIN_WIDTH * (ctx->bits_per_pixel / 8));
	if (keycode == KEY_ARROW_UP)
		rotate_points_x(ctx, ROTATE_STEP);
	else if (keycode == KEY_ARROW_DOWN)
		rotate_points_x(ctx, -ROTATE_STEP);
	else if (keycode == KEY_ARROW_LEFT)
		rotate_points_y(ctx, ROTATE_STEP);
	else if (keycode == KEY_ARROW_RIGHT)
		rotate_points_y(ctx, -ROTATE_STEP);
	else if (keycode == KEY_COMMNA)
		rotate_points_z(ctx, ROTATE_STEP);
	else if (keycode == KEY_DOT)
		rotate_points_z(ctx, -ROTATE_STEP);
	render_image(ctx);
}

int	handle_keydown(int keycode, void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)param;
	if (keycode == KEY_ESCAPE)
		exit_window();
	if (keycode == KEY_ARROW_DOWN || keycode == KEY_ARROW_UP
		|| keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_RIGHT
		|| keycode == KEY_COMMNA || keycode == KEY_DOT)
		_handle_rotation(keycode, ctx);
	if (keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_W)
		_handle_translation(keycode, ctx);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		_handle_scale(keycode, ctx);
	return (0);
}
