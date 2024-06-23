/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:00:55 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 15:17:39 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "libft.h"

#include "render_internal.h"

static void	_init_line_vars(t_line_vars *line, t_point p1, t_point p2)
{
	line->dx = ft_abs((int)p2.x - (int)p1.x);
	line->dy = ft_abs((int)p2.y - (int)p1.y);
	if (p1.x < p2.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (p1.y < p2.y)
		line->sy = 1;
	else
		line->sy = -1;
	if (line->dx > line->dy)
		line->err = line->dx / 2;
	else
		line->err = -line->dy / 2;
	line->x0 = (int)p1.x;
	line->y0 = (int)p1.y;
	line->x1 = (int)p2.x;
	line->y1 = (int)p2.y;
	line->color = 0x00FFFFFF;
}

static void	_update_line_vars(t_line_vars *line)
{
	int	e2;

	e2 = line->err;
	if (e2 > -line->dx)
	{
		line->err -= line->dy;
		line->x0 += line->sx;
	}
	if (e2 < line->dy)
	{
		line->err += line->dx;
		line->y0 += line->sy;
	}
}

void	plot_line(t_ctx *ctx, t_point p1, t_point p2)
{
	t_line_vars	line;

	_init_line_vars(&line, p1, p2);
	while (true)
	{
		plot_pixel(ctx, line.x0, line.y0, line.color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		_update_line_vars(&line);
	}
}
