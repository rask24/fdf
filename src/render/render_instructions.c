/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:11:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/25 00:42:24 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "mlx.h"

static void	_render_instruction(t_ctx *ctx, int *y, int color, char *str)
{
	*y += 20;
	mlx_string_put(ctx->mlx_conf->p_mlx,
		ctx->mlx_conf->p_win, 20, *y, color, str);
}

static void	_show_instruction(t_ctx *ctx)
{
	int	color;
	int	y;

	color = 0xFFFFFF;
	y = 0;
	_render_instruction(ctx, &y, color, "Instructions:");
	_render_instruction(ctx, &y, color, "1 - Isometric View");
	_render_instruction(ctx, &y, color, "2 - Top View");
	_render_instruction(ctx, &y, color, "3 - Oblique View");
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
	_render_instruction(ctx, &y, color, "T - Close Instructions");
	_render_instruction(ctx, &y, color, "ESC - Exit");
}

void	render_instructions(t_ctx *ctx)
{
	int	y;

	if (ctx->view_conf->show_instr)
		_show_instruction(ctx);
	else
	{
		y = 0;
		_render_instruction(ctx, &y, 0xFFFFFF, "Press T to show instructions");
	}
}
