/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:23:11 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 00:55:36 by reasuke          ###   ########.fr       */
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

static void	_render_instruction(t_ctx *ctx, int *y, int color, char *str)
{
	*y += 20;
	mlx_string_put(ctx->mlx_conf->p_mlx,
		ctx->mlx_conf->p_win, 20, *y, color, str);
}

static void	_render_instructions(t_ctx *ctx)
{
	int	color;
	int	y;

	color = 0xFFFFFF;
	y = 0;
	_render_instruction(ctx, &y, color, "Instructions:");
	_render_instruction(ctx, &y, color, "1 - Isometric View");
	_render_instruction(ctx, &y, color, "2 - Top View");
	_render_instruction(ctx, &y, color, "W - Move Up");
	_render_instruction(ctx, &y, color, "A - Move Left");
	_render_instruction(ctx, &y, color, "S - Move Down");
	_render_instruction(ctx, &y, color, "D - Move Right");
	_render_instruction(ctx, &y, color, "F - Zoom In");
	_render_instruction(ctx, &y, color, "G - Zoom Out");
	_render_instruction(ctx, &y, color, "Q - Rotate Left (Y-axis)");
	_render_instruction(ctx, &y, color, "E - Rotate Right (Y-axis)");
	_render_instruction(ctx, &y, color, "R - Rotate Up (X-axis)");
	_render_instruction(ctx, &y, color, "V - Rotate Down (X-axis)");
	_render_instruction(ctx, &y, color, "Z - Rotate Counterclockwise (Z-axis)");
	_render_instruction(ctx, &y, color, "C - Rotate Clockwise (Z-axis)");
	_render_instruction(ctx, &y, color, "X - Cange Color");
	_render_instruction(ctx, &y, color, "ESC - Exit");
}

static void	_reset_points(t_ctx *ctx)
{
	ft_bzero(ctx->mlx_conf->p_data,
		WIN_WIDTH * WIN_HEIGHT * (ctx->mlx_conf->bits_per_pixel / 8));
	clean_points(ctx->data);
	ctx->view_conf->offset_x = 0;
	ctx->view_conf->offset_y = 0;
	init_points(ctx->data);
	init_colors(ctx->data, ctx->view_conf->preset);
}

void	render(t_ctx *ctx, bool only_render, bool is_clean)
{
	if (only_render)
	{
		ft_bzero(ctx->mlx_conf->p_data,
			WIN_WIDTH * WIN_HEIGHT * (ctx->mlx_conf->bits_per_pixel / 8));
		render_image(ctx);
		_render_instructions(ctx);
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
			920, 20, 0xFFFFFF, "isometric view");
	}
	else if (ctx->view_conf->type == TOPVIEW)
	{
		render_image(ctx);
		mlx_string_put(ctx->mlx_conf->p_mlx, ctx->mlx_conf->p_win,
			920, 20, 0xFFFFFF, "top view");
	}
	_render_instructions(ctx);
}
