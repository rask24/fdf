/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_view_conf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:50:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 01:56:29 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "view_conf.h"

t_view_conf	*construct_view_conf(void)
{
	t_view_conf	*view_conf;

	view_conf = (t_view_conf *)malloc(sizeof(t_view_conf));
	if (!view_conf)
		error_exit(strerror(errno));
	view_conf->offset_x = 0;
	view_conf->offset_y = 0;
	view_conf->offset_z = 0;
	view_conf->scale = 1.0;
	view_conf->rot_matrix[0][0] = 1.0;
	view_conf->rot_matrix[0][1] = 0.0;
	view_conf->rot_matrix[0][2] = 0.0;
	view_conf->rot_matrix[1][0] = 0.0;
	view_conf->rot_matrix[1][1] = 1.0;
	view_conf->rot_matrix[1][2] = 0.0;
	view_conf->rot_matrix[2][0] = 0.0;
	view_conf->rot_matrix[2][1] = 0.0;
	view_conf->rot_matrix[2][2] = 1.0;
	return (view_conf);
}
