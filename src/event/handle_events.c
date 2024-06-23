/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:44 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 02:53:12 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "ctx.h"
#include "data.h"
#include "mlx.h"
#include "libft.h"
#include "render.h"

#include "event_internal.h"

void	handle_events(t_ctx *ctx)
{
	mlx_hook(ctx->mlx_conf->p_win, ON_KEYDOWN, KEY_PRESS_MASK,
		handle_keydown, ctx);
	mlx_hook(ctx->mlx_conf->p_win, ON_MOUSEDOWN, NO_EVENT_MASK,
		handle_mousedown, ctx);
	mlx_hook(ctx->mlx_conf->p_win, ON_MOUSEMOVE, NO_EVENT_MASK,
		handle_mousemove, ctx);
	mlx_hook(ctx->mlx_conf->p_win, ON_MOUSEUP, NO_EVENT_MASK,
		handle_mouseup, ctx);
	mlx_hook(ctx->mlx_conf->p_win, ON_DESTROY, NO_EVENT_MASK,
		exit_window, ctx);
}
