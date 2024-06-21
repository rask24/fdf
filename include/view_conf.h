/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_conf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:51:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 01:56:21 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_CONF_H
# define VIEW_CONF_H

typedef struct s_view_conf
{
	int		offset_x;
	int		offset_y;
	int		offset_z;
	double	scale;
	double	rot_matrix[3][3];
}	t_view_conf;

t_view_conf	*construct_view_conf(void);

#endif
