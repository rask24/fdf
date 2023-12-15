/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:00:48 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/15 19:19:49 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	_connect_points_grid_image(t_map *map, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width - 1)
		{
			plot_line(map->points[i][j], map->points[i][j + 1], mlx);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height - 1)
		{
			plot_line(map->points[j][i], map->points[j + 1][i], mlx);
			j++;
		}
		i++;
	}
}

void	render_image(t_map *map, t_mlx *mlx)
{
	_connect_points_grid_image(map, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
