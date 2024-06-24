/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_view_conf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:50:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 11:13:22 by reasuke          ###   ########.fr       */
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
	view_conf->type = ISOMETRIC;
	view_conf->preset = DEFAULT;
	view_conf->click_x = 0;
	view_conf->click_y = 0;
	view_conf->click_btn = 0;
	view_conf->show_instr = false;
	return (view_conf);
}
