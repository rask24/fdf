/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:45:14 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 21:46:35 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ctx.h"
#include "mlx.h"

int	exit_window(t_ctx *ctx)
{
	mlx_destroy_window(ctx->mlx_conf->p_mlx, ctx->mlx_conf->p_win);
	exit(EXIT_SUCCESS);
	return (0);
}
