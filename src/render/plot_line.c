/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:00:55 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 00:45:41 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "libft.h"
#include "utils.h"

#include "render_internal.h"

static void	_init_line_vars(t_line_vars *line, t_point p1, t_point p2,
				double *depth_buffer)
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
	line->c1 = p1.color;
	line->c2 = p2.color;
	line->color = p1.color;
	line->depth_buffer = depth_buffer;
}

static void	_update_line_vars(t_line_vars *line)
{
	int		e2;
	double	total_distance;
	double	current_distance;
	double	ratio;

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
	total_distance = sqrt((line->dx * line->dx) + (line->dy * line->dy));
	current_distance = sqrt(((line->x0 - line->x1) * (line->x0 - line->x1))
			+ ((line->y0 - line->y1) * (line->y0 - line->y1)));
	ratio = 1 - (current_distance / total_distance);
	line->color = interpolate_color(line->c1, line->c2, ratio);
}

static double	_interpolate_z(t_point p1, t_point p2, int x, int y)
{
	double	total_distance;
	double	current_distance;
	double	ratio;

	total_distance = sqrt(((p2.x - p1.x) * (p2.x - p1.x))
			+ ((p2.y - p1.y) * (p2.y - p1.y)));
	current_distance = sqrt(((x - p1.x) * (x - p1.x))
			+ ((y - p1.y) * (y - p1.y)));
	ratio = 1 - (current_distance / total_distance);
	return (p1.z + ((p2.z - p1.z) * ratio));
}

void	plot_line(t_ctx *ctx, t_point p1, t_point p2, double *depth_buffer)
{
	t_line_vars	line;
	double		z;
	int			win_x;
	int			win_y;

	_init_line_vars(&line, p1, p2, depth_buffer);
	while (true)
	{
		z = _interpolate_z(p1, p2, line.x0, line.y0);
		(void)z;
		win_x = line.x0 + (WIN_WIDTH - 1) / 2 + ctx->view_conf->offset_x;
		win_y = line.y0 + (WIN_HEIGHT - 1) / 2 + ctx->view_conf->offset_y;
		if (win_x >= 0 && win_x < WIN_WIDTH && win_y >= 0 && win_y < WIN_HEIGHT
			&& ft_fchmax(depth_buffer + win_y * WIN_WIDTH + win_x, z))
			plot_pixel(ctx, win_x, win_y, line.color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		_update_line_vars(&line);
	}
}
