/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_conf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:51:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 13:33:07 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_CONF_H
# define VIEW_CONF_H

typedef enum e_type
{
	ISOMETRIC,
	TOPVIEW,
}	t_type;

typedef struct s_view_conf
{
	int		offset_x;
	int		offset_y;
	int		offset_z;
	double	scale;
	t_type	type;
}	t_view_conf;

t_view_conf	*construct_view_conf(void);

#endif
