/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:20:07 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/22 14:41:00 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "mlx_config.h"

void	handle_events(t_ctx *ctx)
{
	mlx_hook(ctx->win_ptr, ON_KEYDOWN, KEY_PRESS_MASK, handle_keydown, ctx);
	mlx_hook(ctx->win_ptr, ON_DESTROY, NO_EVENT_MASK, exit_window, NULL);
}
