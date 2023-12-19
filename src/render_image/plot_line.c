/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:59:57 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/19 19:29:12 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_set_line_conf(t_line_conf *lc, t_point *p0, t_point *p1)
{
	double	dx;
	double	dy;

	lc->steep = fabs(p1->y - p0->y) > fabs(p1->x - p0->x);
	lc->color_start = p0->color;
	lc->color_end = p1->color;
	if (lc->steep)
	{
		ft_fswap(&p0->x, &p0->y);
		ft_fswap(&p1->x, &p1->y);
	}
	if (p0->x > p1->x)
	{
		ft_fswap(&p0->x, &p1->x);
		ft_fswap(&p0->y, &p1->y);
		ft_swap(&lc->color_start, &lc->color_end);
	}
	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dx == 0.0)
		lc->gradient = 1.0;
	else
		lc->gradient = dy / dx;
}

static void	_handle_first_endpoint(t_line_conf *lc, t_point p0, t_mlx *mlx)
{
	double	x_end;
	double	y_end;
	double	x_gap;

	x_end = round(p0.x);
	y_end = p0.y + lc->gradient * (x_end - p0.x);
	x_gap = rfpart(p0.x + 0.5);
	lc->x_pxl1 = x_end;
	lc->y_pxl1 = floor(y_end);
	if (lc->steep)
	{
		plot_point_to_image(mlx, lc->y_pxl1, lc->x_pxl1,
			color_gradient(0x0, lc->color_start, rfpart(y_end * x_gap)));
		plot_point_to_image(mlx, lc->y_pxl1 + 1, lc->x_pxl1,
			color_gradient(0x0, lc->color_start, fpart(y_end * x_gap)));
	}
	else
	{
		plot_point_to_image(mlx, lc->x_pxl1, lc->y_pxl1,
			color_gradient(0x0, lc->color_start, rfpart(y_end * x_gap)));
		plot_point_to_image(mlx, lc->x_pxl1, lc->y_pxl1 + 1,
			color_gradient(0x0, lc->color_start, fpart(y_end * x_gap)));
	}
	lc->intery = y_end + lc->gradient;
}

static void	_handle_second_endpoint(t_line_conf *lc, t_point p1, t_mlx *mlx)
{
	double	x_end;
	double	y_end;
	double	x_gap;

	x_end = round(p1.x);
	y_end = p1.y + lc->gradient * (x_end - p1.x);
	x_gap = fpart(p1.x + 0.5);
	lc->x_pxl2 = x_end;
	lc->y_pxl2 = floor(y_end);
	if (lc->steep)
	{
		plot_point_to_image(mlx, lc->y_pxl2, lc->x_pxl2,
			color_gradient(0x0, lc->color_end, rfpart(y_end * x_gap)));
		plot_point_to_image(mlx, lc->y_pxl2 + 1, lc->x_pxl2,
			color_gradient(0x0, lc->color_end, fpart(y_end * x_gap)));
	}
	else
	{
		plot_point_to_image(mlx, lc->x_pxl2, lc->y_pxl2,
			color_gradient(0x0, lc->color_end, rfpart(y_end * x_gap)));
		plot_point_to_image(mlx, lc->x_pxl2, lc->y_pxl2 + 1,
			color_gradient(0x0, lc->color_end, fpart(y_end * x_gap)));
	}
}

void	_main_loop(t_line_conf lc, t_point p0, t_point p1, t_mlx *mlx)
{
	int		x;
	int		color;
	double	ratio;

	x = lc.x_pxl1;
	while (++x < lc.x_pxl2 - 1)
	{
		ratio = calc_ratio(p0, p1, x, lc.intery);
		color = color_gradient(lc.color_start, lc.color_end, ratio);
		if (lc.steep)
		{
			plot_point_to_image(mlx, floor(lc.intery), x,
				color_gradient(0x0, color, rfpart(lc.intery)));
			plot_point_to_image(mlx, floor(lc.intery) + 1, x,
				color_gradient(0x0, color, fpart(lc.intery)));
		}
		else
		{
			plot_point_to_image(mlx, x, floor(lc.intery),
				color_gradient(0x0, color, rfpart(lc.intery)));
			plot_point_to_image(mlx, x, floor(lc.intery) + 1,
				color_gradient(0x0, color, fpart(lc.intery)));
		}
		lc.intery += lc.gradient;
	}
}

void	plot_line(t_point p0, t_point p1, t_mlx *mlx)
{
	t_line_conf	lc;

	_set_line_conf(&lc, &p0, &p1);
	_handle_first_endpoint(&lc, p0, mlx);
	_handle_second_endpoint(&lc, p1, mlx);
	_main_loop(lc, p0, p1, mlx);
}
