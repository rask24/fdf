/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_point_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:09:02 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/19 19:09:24 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_point_to_image(t_mlx *mlx, int x, int y, int color)
{
	int		center_window_x;
	int		center_window_y;

	center_window_x = (WIN_WIDTH - 1) / 2;
	center_window_y = (WIN_HEIGHT - 1) / 2;
	my_mlx_pixel_put(mlx, x + center_window_x, y + center_window_y, color);
}
