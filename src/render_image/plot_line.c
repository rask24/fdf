/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:59:57 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/19 19:22:43 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_set_xw(t_xw *xw, t_point *p0, t_point *p1)
{
	xw->steep = fabs(p1->y - p0->y) > fabs(p1->x - p0->x);
	xw->color_start = p0->color;
	xw->color_end = p1->color;
	if (xw->steep)
	{
		ft_fswap(&p0->x, &p0->y);
		ft_fswap(&p1->x, &p1->y);
	}
	if (p0->x > p1->x)
	{
		ft_fswap(&p0->x, &p1->x);
		ft_fswap(&p0->y, &p1->y);
		ft_swap(&xw->color_start, &xw->color_end);
	}
	xw->dx = p1->x - p0->x;
	xw->dy = p1->y - p0->y;
	if (xw->dx == 0.0)
		xw->gradient = 1.0;
	else
		xw->gradient = xw->dy / xw->dx;
}

static void	_handle_first_endpoint(t_xw *xw, t_point p0, t_mlx *mlx)
{
	double	x_end;
	double	y_end;
	double	x_gap;

	x_end = round(p0.x);
	y_end = p0.y + xw->gradient * (x_end - p0.x);
	x_gap = rfpart(p0.x + 0.5);
	xw->x_pxl1 = x_end;
	xw->y_pxl1 = floor(y_end);
	if (xw->steep)
	{
		plot_point_to_image(mlx, xw->y_pxl1, xw->x_pxl1,
			color_gradient(0x0, xw->color_start, rfpart(y_end * x_gap)));
		plot_point_to_image(mlx, xw->y_pxl1 + 1, xw->x_pxl1,
			color_gradient(0x0, xw->color_start, fpart(y_end * x_gap)));
	}
	else
	{
		plot_point_to_image(mlx, xw->x_pxl1, xw->y_pxl1,
			color_gradient(0x0, xw->color_start, rfpart(y_end * x_gap)));
		plot_point_to_image(mlx, xw->x_pxl1, xw->y_pxl1 + 1,
			color_gradient(0x0, xw->color_start, fpart(y_end * x_gap)));
	}
	xw->intery = y_end + xw->gradient;
}

static void	_handle_second_endpoint(t_xw *xw, t_point p1, t_mlx *mlx)
{
	double	x_end;
	double	y_end;
	double	x_gap;

	x_end = round(p1.x);
	y_end = p1.y + xw->gradient * (x_end - p1.x);
	x_gap = fpart(p1.x + 0.5);
	xw->x_pxl2 = x_end;
	xw->y_pxl2 = floor(y_end);
	if (xw->steep)
	{
		plot_point_to_image(mlx, xw->y_pxl2, xw->x_pxl2,
			color_gradient(0x0, xw->color_end, rfpart(y_end * x_gap)));
		plot_point_to_image(mlx, xw->y_pxl2 + 1, xw->x_pxl2,
			color_gradient(0x0, xw->color_end, fpart(y_end * x_gap)));
	}
	else
	{
		plot_point_to_image(mlx, xw->x_pxl2, xw->y_pxl2,
			color_gradient(0x0, xw->color_end, rfpart(y_end * x_gap)));
		plot_point_to_image(mlx, xw->x_pxl2, xw->y_pxl2 + 1,
			color_gradient(0x0, xw->color_end, fpart(y_end * x_gap)));
	}
}

void	_main_loop(t_xw xw, t_point p0, t_point p1, t_mlx *mlx)
{
	int		x;
	int		color;
	double	ratio;

	x = xw.x_pxl1;
	while (++x < xw.x_pxl2 - 1)
	{
		ratio = calc_ratio(p0, p1, x, xw.intery);
		color = color_gradient(xw.color_start, xw.color_end, ratio);
		if (xw.steep)
		{
			plot_point_to_image(mlx, floor(xw.intery), x,
				color_gradient(0x0, color, rfpart(xw.intery)));
			plot_point_to_image(mlx, floor(xw.intery) + 1, x,
				color_gradient(0x0, color, fpart(xw.intery)));
		}
		else
		{
			plot_point_to_image(mlx, x, floor(xw.intery),
				color_gradient(0x0, color, rfpart(xw.intery)));
			plot_point_to_image(mlx, x, floor(xw.intery) + 1,
				color_gradient(0x0, color, fpart(xw.intery)));
		}
		xw.intery += xw.gradient;
	}
}

void	plot_line(t_point p0, t_point p1, t_mlx *mlx)
{
	t_xw	xw;

	_set_xw(&xw, &p0, &p1);
	_handle_first_endpoint(&xw, p0, mlx);
	_handle_second_endpoint(&xw, p1, mlx);
	_main_loop(xw, p0, p1, mlx);
}
