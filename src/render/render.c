/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:23:11 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 23:16:44 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ctx.h"
#include "libft.h"
#include "mlx.h"
#include "render.h"
#include "view_conf.h"

#include "render_internal.h"

void	render(t_ctx *ctx)
{
	ft_bzero(ctx->mlx_conf->p_data,
		WIN_WIDTH * WIN_HEIGHT * (ctx->mlx_conf->bits_per_pixel / 8));
	render_image(ctx);
	render_instructions(ctx);
	return ;
}
