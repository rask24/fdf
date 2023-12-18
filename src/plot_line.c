/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:59:57 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/18 17:49:37 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	_set_color(t_line_conf *lc, int p0_color, int p1_color)
{
	if (p0_color != 0xDDDDDD)
		lc->color = p0_color;
	else if (p1_color != 0xDDDDDD)
		lc->color = p1_color;
	else
		lc->color = 0xDDDDDD;
}

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
	_set_color(lc, p0->color, p1->color);
}

void	_plot_point_to_image(t_mlx *mlx, int x, int y, int color)
{
	int		center_window_x;
	int		center_window_y;

	center_window_x = (WIN_WIDTH - 1) / 2;
	center_window_y = (WIN_HEIGHT - 1) / 2;
	my_mlx_pixel_put(mlx, x + center_window_x, y + center_window_y, color);
}

void	plot_line(t_point p0, t_point p1, t_mlx *mlx)
{
	t_line_conf	lc;

	_set_line_conf(&lc, &p0, &p1);
	while (lc.x <= p1.x)
	{
		if (lc.steep)
			_plot_point_to_image(mlx, lc.y, lc.x, lc.color);
		else
			_plot_point_to_image(mlx, lc.x, lc.y, lc.color);
		lc.error -= lc.dy;
		if (lc.error < 0)
		{
			lc.y += lc.step_y;
			lc.error += lc.dx;
		}
		lc.x++;
	}
}
