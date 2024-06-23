/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mousedown.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:29:56 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 02:40:04 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ctx.h"
#include "mlx_conf.h"
#include "render.h"

int	handle_mousedown(int button, int x, int y, t_ctx *ctx)
{
	(void)x;
	(void)y;
	if (button == MOUSE_RIGHT)
	{
		ctx->view_conf->preset = (ctx->view_conf->preset + 1) % NUM_PRESETS;
		init_colors(ctx->data, ctx->view_conf->preset);
		render(ctx, true, false);
	}
	return (0);
}
