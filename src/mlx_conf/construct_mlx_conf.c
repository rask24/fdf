/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_mlx_conf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:42:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 01:44:19 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "mlx_conf.h"
#include "utils.h"

static void	_set_mlx(t_mlx_conf *mlx_conf)
{
	mlx_conf->p_mlx = mlx_init();
	if (!mlx_conf->p_mlx)
		error_exit("mlx_init() failed");
}

static void	_set_win(t_mlx_conf *mlx_conf)
{
	mlx_conf->p_win = mlx_new_window(mlx_conf->p_mlx,
			WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!mlx_conf->p_win)
		error_exit("mlx_new_window() failed");
}

static void	_set_img(t_mlx_conf *mlx_conf)
{
	mlx_conf->p_img = mlx_new_image(mlx_conf->p_mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx_conf->p_img)
		error_exit("mlx_new_image() failed");
}

static void	_set_data(t_mlx_conf *mlx_conf)
{
	mlx_conf->p_data = mlx_get_data_addr(mlx_conf->p_img,
			&mlx_conf->bits_per_pixel, &mlx_conf->line_length,
			&mlx_conf->endian);
	if (!mlx_conf->p_data)
		error_exit("mlx_get_data_addr() failed");
}

t_mlx_conf	*construct_mlx_conf(void)
{
	t_mlx_conf	*mlx_conf;

	mlx_conf = malloc(sizeof(t_mlx_conf));
	if (!mlx_conf)
		error_exit(strerror(errno));
	_set_mlx(mlx_conf);
	_set_win(mlx_conf);
	_set_img(mlx_conf);
	_set_data(mlx_conf);
	return (mlx_conf);
}
