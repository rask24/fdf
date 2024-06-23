/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:44 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 19:14:53 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ctx.h"
#include "mlx.h"

static int	_handle_keydown(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(ctx->mlx_conf->p_mlx, ctx->mlx_conf->p_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	handle_events(t_ctx *ctx)
{
	mlx_hook(ctx->mlx_conf->p_win, ON_KEYDOWN, KEY_PRESS_MASK,
		_handle_keydown, ctx);
}