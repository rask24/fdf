/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:54:41 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/19 17:53:23 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

typedef struct s_xw
{
	bool	steep;
	double	dx;
	double	dy;
	double	gradient;
	double	x_pxl1;
	double	y_pxl1;
	double	x_pxl2;
	double	y_pxl2;
	double	intery;
	int		color_start;
	int		color_end;
}	t_xw;

double	fpart(double x)
{
	return (x - floor(x));
}

double	rfpart(double x)
{
	return (1 - fpart(x));
}

static void	_set_xw(t_xw *xw, t_point p0, t_point p1)
{
	xw->steep = fabs(p1.y - p0.y) > fabs(p1.x - p0.x);
	xw->color_start = p0.color;
	xw->color_end = p1.color;
	if (xw->steep)
	{
		ft_fswap(&p0.x, &p0.y);
		ft_fswap(&p1.x, &p1.y);
	}
	if (p0.x > p1.x)
	{
		ft_fswap(&p0.x, &p1.x);
		ft_fswap(&p0.y, &p1.y);
		ft_swap(&xw->color_start, &xw->color_end);
	}
	xw->dx = p1.x - p0.x;
	xw->dy = p1.y - p0.y;
	if (xw->dx == 0.0)
		xw->gradient = 1.0;
	else
		xw->gradient = xw->dy / xw->dx;
}

static void	_handle_first_endpoint(t_xw *xw, t_point p0, t_point p1, t_mlx *mlx)
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
		_plot_point_to_image(mlx, xw->y_pxl1, xw->x_pxl1,
			color_gradient(xw->color_end, 0x0, rfpart(y_end * x_gap)));
		_plot_point_to_image(mlx, xw->y_pxl1 + 1, xw->x_pxl1,
			color_gradient(xw->color_end, 0x0, fpart(y_end * x_gap)));
	}
	else
	{
		_plot_point_to_image(mlx, xw->x_pxl1, xw->y_pxl1,
			color_gradient(xw->color_end, 0x0, rfpart(y_end * x_gap)));
		_plot_point_to_image(mlx, xw->x_pxl1, xw->y_pxl1 + 1,
			color_gradient(xw->color_end, 0x0, fpart(y_end * x_gap)));
	}
	xw->intery = y_end + xw->gradient;
}

static void	_handle_second_endpoint(
		t_xw *xw, t_point p0, t_point p1, t_mlx *mlx)
{
	double	x_end;
	double	y_end;
	double	x_gap;

	x_end = round(p1.x);
	y_end = p1.y + xw->gradient * (x_end - p1.x);
	x_gap = rfpart(p1.x + 0.5);
	xw->x_pxl2 = x_end;
	xw->y_pxl2 = floor(y_end);
	if (xw->steep)
	{
		_plot_point_to_image(mlx, xw->y_pxl2, xw->x_pxl2,
			color_gradient(xw->color_start, 0x0, rfpart(y_end * x_gap)));
		_plot_point_to_image(mlx, xw->y_pxl2 + 1, xw->x_pxl2,
			color_gradient(xw->color_start, 0x0, fpart(y_end * x_gap)));
	}
	else
	{
		_plot_point_to_image(mlx, xw->x_pxl2, xw->y_pxl2,
			color_gradient(xw->color_start, 0x0, rfpart(y_end * x_gap)));
		_plot_point_to_image(mlx, xw->x_pxl2, xw->y_pxl2 + 1,
			color_gradient(xw->color_start, 0x0, fpart(y_end * x_gap)));
	}
}

static double	_calc_ratio(t_point p0, t_point p1, double x, double y)
{
	double	dist;

	dist = sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y));
	return (sqrt((x - p0.x) * (x - p0.x) + (y - p0.y) * (y - p0.y)) / dist);
}

void	plot_line(t_point p0, t_point p1, t_mlx *mlx)
{
	t_xw	xw;
	int		x;
	int		y;
	int		color;
	double	ratio;

	_set_xw(&xw, p0, p1);
	_handle_first_endpoint(&xw, p0, p1, mlx);
	_handle_second_endpoint(&xw, p0, p1, mlx);
	if (xw.steep)
	{
		x = xw.x_pxl1 + 1;
		ratio = _calc_ratio(p0, p1, x, xw.intery);
		color = color_gradient(xw.color_start, xw.color_end, ratio);
		while (x < xw.x_pxl2 - 1)
		{
			_plot_point_to_image(mlx, floor(xw.intery), x,
				color_gradient(color, 0x0, rfpart(xw.intery)));
			_plot_point_to_image(mlx, floor(xw.intery) + 1, x,
				color_gradient(color, 0x0, fpart(xw.intery)));
			xw.intery += xw.gradient;
			x++;
		}
	}
	else
	{
		x = xw.x_pxl1 + 1;
		ratio = _calc_ratio(p0, p1, x, xw.intery);
		color = color_gradient(xw.color_start, xw.color_end, ratio);
		while (x < xw.x_pxl2 - 1)
		{
			_plot_point_to_image(mlx, x, floor(xw.intery),
				color_gradient(color, 0x0, rfpart(xw.intery)));
			_plot_point_to_image(mlx, x, floor(xw.intery) + 1,
				color_gradient(color, 0x0, fpart(xw.intery)));
			xw.intery += xw.gradient;
			x++;
		}
	}
}



