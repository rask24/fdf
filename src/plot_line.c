/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:59:57 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/18 21:01:30 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	_set_color(t_line_conf *lc, int p0_color, int p1_color)
// {
// 	if (p0_color != DEFAULT_COLOR_BOTTOM)
// 		lc->color_start = p0_color;
// 	else if (p1_color != DEFAULT_COLOR_BOTTOM)
// 		lc->color_start = p1_color;
// 	else
// 		lc->color_start = DEFAULT_COLOR_BOTTOM;
// }

void	_set_line_conf(t_line_conf *lc, t_point *p0, t_point *p1)
{
	lc->steep = fabs(p1->y - p0->y) > fabs(p1->x - p0->x);
	if (lc->steep)
	{
		ft_fswap(&p0->x, &p0->y);
		ft_fswap(&p1->x, &p1->y);
	}
	if (p0->x > p1->x)
	{
		ft_fswap(&p0->x, &p1->x);
		ft_fswap(&p0->y, &p1->y);
	}
	lc->dx = p1->x - p0->x;
	lc->dy = fabs(p1->y - p0->y);
	lc->error = lc->dx / 2;
	lc->y = p0->y;
	lc->x = p0->x;
	if (p0->y < p1->y)
		lc->step_y = 1;
	else
		lc->step_y = -1;
	lc->color_start = p0->color;
	lc->color_end = p1->color;
}

void	_plot_point_to_image(t_mlx *mlx, int x, int y, int color)
{
	int		center_window_x;
	int		center_window_y;

	center_window_x = (WIN_WIDTH - 1) / 2;
	center_window_y = (WIN_HEIGHT - 1) / 2;
	my_mlx_pixel_put(mlx, x + center_window_x, y + center_window_y, color);
}

static double	_calc_ratio(t_point p0, t_point p1, double x, double y)
{
	double	dist;

	dist = sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y));
	return (sqrt((x - p0.x) * (x - p0.x) + (y - p0.y) * (y - p0.y)) / dist);
}

void	plot_line(t_point p0, t_point p1, t_mlx *mlx)
{
	t_line_conf	lc;
	double		ratio;
	int			color;

	_set_line_conf(&lc, &p0, &p1);
	while (lc.x <= p1.x)
	{
		ratio = _calc_ratio(p0, p1, lc.x, lc.y);
		color = color_gradient(lc.color_start, lc.color_end, ratio);
		if (lc.steep)
			_plot_point_to_image(mlx, lc.y, lc.x, color);
		else
			_plot_point_to_image(mlx, lc.x, lc.y, color);
		lc.error -= lc.dy;
		if (lc.error < 0)
		{
			lc.y += lc.step_y;
			lc.error += lc.dx;
		}
		lc.x++;
	}
}
