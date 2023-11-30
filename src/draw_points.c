/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:51:11 by reasuke           #+#    #+#             */
/*   Updated: 2023/11/28 21:24:28by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	_bresenham(t_point p0, t_point p1, t_mlx *mlx)
{
	bool	steep;
	int		dx;
	int		dy;
	int		error;
	int		x;
	int		y;
	int		step_y;
	int		color;

	steep = abs(p1.y - p0.y) > abs(p1.x - p0.x);
	if (steep)
	{
		ft_swap(&p0.x, &p0.y);
		ft_swap(&p1.x, &p1.y);
	}
	if (p0.x > p1.x)
	{
		ft_swap(&p0.x, &p1.x);
		ft_swap(&p0.y, &p1.y);
	}
	dx = p1.x - p0.x;
	dy = abs(p1.y - p0.y);
	error = dx / 2;
	y = p0.y;
	x = p0.x;
	if (p0.y < p1.y)
		step_y = 1;
	else
		step_y = -1;
	if (p0.color != 0xDDDDDD)
		color = p0.color;
	else if (p1.color != 0xDDDDDD)
		color = p1.color;
	else
		color = 0xDDDDDD;
	while (x <= p1.x)
	{
		if (steep)
			my_mlx_pixel_put(mlx, y, x, color);
		else
			my_mlx_pixel_put(mlx, x, y, color);
		error -= dy;
		if (error < 0)
		{
			y += step_y;
			error += dx;
		}
		x++;
	}
}

void	_draw_line(t_map map, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width - 1)
		{
			_bresenham(map.points[i][j], map.points[i][j + 1], mlx);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map.width)
	{
		j = 0;
		while (j < map.height - 1)
		{
			_bresenham(map.points[j][i], map.points[j + 1][i], mlx);
			j++;
		}
		i++;
	}
}

void	draw_points(t_map map)
{
	t_mlx	mlx;

	set_mlx(&mlx);
	_draw_line(map, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, ON_KEYDOWN, 1L << 0, handle_keydown, NULL);
	mlx_hook(mlx.win_ptr, ON_DESTROY, 0L, exit_window, NULL);
	mlx_loop(mlx.mlx_ptr);
}
