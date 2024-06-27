/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 02:09:33 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 02:16:44 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "mlx_conf.h"
#include "utils.h"

void	reset_image(t_mlx_conf *mlx_conf)
{
	mlx_destroy_image(mlx_conf->p_mlx, mlx_conf->p_img);
	mlx_conf->p_img = mlx_new_image(mlx_conf->p_mlx, WIN_WIDTH, WIN_HEIGHT);
	if (mlx_conf->p_img == NULL)
		error_exit("mlx_new_image() failed");
	mlx_conf->p_data = mlx_get_data_addr(mlx_conf->p_img,
		&mlx_conf->bits_per_pixel, &mlx_conf->line_length, &mlx_conf->endian);
	if (mlx_conf->p_data == NULL)
		error_exit("mlx_get_data_addr() failed");
}
