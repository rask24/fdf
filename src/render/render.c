/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:23:11 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 00:27:13 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include "render_internal.h"

void	render(t_ctx *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->data->rows)
	{
		j = 0;
		while (j < ctx->data->cols)
		{
			plot_pixel(ctx, ctx->data->points[i][j].x,
				ctx->data->points[i][j].y, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
