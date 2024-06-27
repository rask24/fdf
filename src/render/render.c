/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:23:11 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 02:11:13 by reasuke          ###   ########.fr       */
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
	reset_image(ctx->mlx_conf);
	render_image(ctx);
	render_instructions(ctx);
	return ;
}
