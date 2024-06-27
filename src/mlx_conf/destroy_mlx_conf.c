/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx_conf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 02:59:58 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 03:13:14 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "mlx_conf.h"

void	destroy_mlx_conf(t_mlx_conf *mlx_conf)
{
	if (mlx_conf == NULL)
		return ;
	if (mlx_conf->p_img)
		mlx_destroy_image(mlx_conf->p_mlx, mlx_conf->p_img);
	if (mlx_conf->p_win)
		mlx_destroy_window(mlx_conf->p_mlx, mlx_conf->p_win);
	free(mlx_conf);
}
