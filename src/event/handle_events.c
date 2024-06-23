/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:44 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 20:48:43 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "ctx.h"
#include "data.h"
#include "mlx.h"
#include "libft.h"
#include "render.h"

static int	_exit_window(t_ctx *ctx)
{
	mlx_destroy_window(ctx->mlx_conf->p_mlx, ctx->mlx_conf->p_win);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	draw_test_string(t_ctx *ctx, int x, int y, char *str)
{
	int	color;

	color = 0xFFFFFF;
	mlx_string_put(ctx->mlx_conf->p_mlx, ctx->mlx_conf->p_win,
		x, y, color, str);
}

static int	_handle_keydown(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_ESCAPE)
		_exit_window(ctx);
	else if (keycode == KEY_1)
	{
		ft_bzero(ctx->mlx_conf->p_data,
			WIN_WIDTH * WIN_HEIGHT * (ctx->mlx_conf->bits_per_pixel / 8));
		clean_points(ctx->data);
		init_points(ctx->data);
		init_colors(ctx->data);
		apply_operation(ctx->data, rotate_z, M_PI_4);
		apply_operation(ctx->data, rotate_x, atan(1 / sqrt(2)));
		render(ctx);
		draw_test_string(ctx, 20, 20, "isometric view");
	}
	else if (keycode == KEY_2)
	{
		ft_bzero(ctx->mlx_conf->p_data,
			WIN_WIDTH * WIN_HEIGHT * (ctx->mlx_conf->bits_per_pixel / 8));
		clean_points(ctx->data);
		init_points(ctx->data);
		init_colors(ctx->data);
		render(ctx);
		draw_test_string(ctx, 20, 20, "top view");
	}
	return (0);
}

void	handle_events(t_ctx *ctx)
{
	mlx_hook(ctx->mlx_conf->p_win, ON_KEYDOWN, KEY_PRESS_MASK,
		_handle_keydown, ctx);
	mlx_hook(ctx->mlx_conf->p_win, ON_DESTROY, NO_EVENT_MASK,
		_exit_window, ctx);
}
