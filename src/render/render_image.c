/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:59:22 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 00:59:45 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "mlx.h"
#include "render.h"
#include "utils.h"

#include "render_internal.h"

static double	*_construct_depth_buffer(void)
{
	double	*depth_buffer;
	int		i;

	depth_buffer = malloc(sizeof(double) * WIN_HEIGHT * WIN_WIDTH);
	if (depth_buffer == NULL)
		error_exit(strerror(errno));
	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		depth_buffer[i] = -INFINITY;
		i++;
	}
	return (depth_buffer);
}

static t_point	_transform_point(t_ctx *ctx, t_point p)
{
	if (ctx->view_conf->type == OBLIQUE)
	{
		p.x -= SHRINK_FACTOR * cos(M_PI_4) * p.z;
		p.y -= SHRINK_FACTOR * sin(M_PI_4) * p.z;
	}
	return (p);
}

static void	_plot_grid_lines(t_ctx *ctx, int i, int j, double *depth_buffer)
{
	t_point	p1;
	t_point	p2;

	if (i < ctx->data->rows - 1)
	{
		p1 = _transform_point(ctx, ctx->data->points[i][j]);
		p2 = _transform_point(ctx, ctx->data->points[i + 1][j]);
		plot_line(ctx, p1, p2, depth_buffer);
	}
	if (j < ctx->data->cols - 1)
	{
		p1 = _transform_point(ctx, ctx->data->points[i][j]);
		p2 = _transform_point(ctx, ctx->data->points[i][j + 1]);
		plot_line(ctx, p1, p2, depth_buffer);
	}
}

void	render_image(t_ctx *ctx)
{
	int		i;
	int		j;
	double	*depth_buffer;

	depth_buffer = _construct_depth_buffer();
	i = 0;
	while (i < ctx->data->rows)
	{
		j = 0;
		while (j < ctx->data->cols)
		{
			_plot_grid_lines(ctx, i, j, depth_buffer);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ctx->mlx_conf->p_mlx,
		ctx->mlx_conf->p_win, ctx->mlx_conf->p_img, 0, 0);
	free(depth_buffer);
}
