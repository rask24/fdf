/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:20:07 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/20 15:21:03 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_window(void)
{
	exit(0);
	return (0);
}

void	handle_events(t_ctx *ctx)
{
	mlx_hook(ctx->win_ptr, ON_KEYDOWN, KEY_PRESS_MASK, handle_keydown, ctx);
	mlx_hook(ctx->win_ptr, ON_DESTROY, NO_EVENT_MASK, exit_window, NULL);
}
