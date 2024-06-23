/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_conf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:51:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/24 01:01:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_CONF_H
# define VIEW_CONF_H

typedef enum e_type
{
	ISOMETRIC,
	TOPVIEW,
}	t_type;

typedef enum e_preset
{
	DEFAULT,
	DARK,
	TROPICAL,
	PASTEL,
}	t_preset;

typedef struct s_view_conf
{
	int			offset_x;
	int			offset_y;
	int			offset_z;
	double		scale;
	t_type		type;
	t_preset	preset;
}	t_view_conf;

t_view_conf	*construct_view_conf(void);

#endif
