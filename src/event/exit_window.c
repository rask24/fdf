/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:45:14 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 03:13:52 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ctx.h"
#include "data.h"
#include "mlx.h"
#include "mlx_conf.h"

int	exit_window(t_ctx *ctx)
{
	destroy_data(ctx->data);
	destroy_mlx_conf(ctx->mlx_conf);
	free(ctx->view_conf);
	free(ctx);
	exit(EXIT_SUCCESS);
	return (0);
}
