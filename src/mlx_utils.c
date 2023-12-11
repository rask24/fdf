/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:24:29 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/11 13:29:06 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->data_addr = mlx_get_data_addr(mlx->img_ptr,
			&mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
}

void	my_mlx_pixel_put(t_mlx mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || WIN_WIDTH <= x || y < 0 || WIN_HEIGHT <= y)
		return ;
	dst = mlx.data_addr
		+ (y * mlx.line_length + x * (mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
