/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:44 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 21:04:48 by reasuke          ###   ########.fr       */
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

static int	_handle_keydown(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_ESCAPE)
		_exit_window(ctx);
	else if (keycode == KEY_1)
	{
		ctx->view_conf->type = ISOMETRIC;
		render(ctx, true);
	}
	else if (keycode == KEY_2)
	{
		ctx->view_conf->type = TOPVIEW;
		render(ctx, true);
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
