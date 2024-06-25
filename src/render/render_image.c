/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:59:22 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/25 19:49:06 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx.h"
#include "render.h"

#include "render_internal.h"

static t_point	_transform_point(t_ctx *ctx, t_point p)
{
	if (ctx->view_conf->type == OBLIQUE)
	{
		p.x = p.x - 0.5 * cos(M_PI_4) * p.z;
		p.y = p.y - 0.5 * sin(M_PI_4) * p.z;
	}
	return (p);
}

static void	_plot_row_line(t_ctx *ctx, int i, int j)
{
	t_point	p1;
	t_point	p2;

	if (j == ctx->data->cols - 1)
		return ;
	p1 = _transform_point(ctx, ctx->data->points[i][j]);
	p2 = _transform_point(ctx, ctx->data->points[i][j + 1]);
	plot_line(ctx, p1, p2);
}

static void	_plot_col_line(t_ctx *ctx, int i, int j)
{
	t_point	p1;
	t_point	p2;

	if (i == ctx->data->rows - 1)
		return ;
	p1 = _transform_point(ctx, ctx->data->points[i][j]);
	p2 = _transform_point(ctx, ctx->data->points[i + 1][j]);
	plot_line(ctx, p1, p2);
}

void	render_image(t_ctx *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->data->rows)
	{
		j = 0;
		while (j < ctx->data->cols)
		{
			_plot_row_line(ctx, i, j);
			_plot_col_line(ctx, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ctx->mlx_conf->p_mlx,
		ctx->mlx_conf->p_win, ctx->mlx_conf->p_img, 0, 0);
}
