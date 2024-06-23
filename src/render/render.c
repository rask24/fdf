/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:23:11 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 20:15:50 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render.h"

#include "render_internal.h"

static void	_plot_row_line(t_ctx *ctx, int i, int j)
{
	t_point	p1;
	t_point	p2;

	if (j == ctx->data->cols - 1)
		return ;
	p1 = ctx->data->points[i][j];
	p2 = ctx->data->points[i][j + 1];
	plot_line(ctx, p1, p2);
}

static void	_plot_col_line(t_ctx *ctx, int i, int j)
{
	t_point	p1;
	t_point	p2;

	if (i == ctx->data->rows - 1)
		return ;
	p1 = ctx->data->points[i][j];
	p2 = ctx->data->points[i + 1][j];
	plot_line(ctx, p1, p2);
}

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
			_plot_row_line(ctx, i, j);
			_plot_col_line(ctx, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ctx->mlx_conf->p_mlx,
		ctx->mlx_conf->p_win, ctx->mlx_conf->p_img, 0, 0);
}
