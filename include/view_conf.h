/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_conf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:51:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/07/01 17:19:50 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_CONF_H
# define VIEW_CONF_H

# include <stdbool.h>

typedef enum e_type
{
	ISOMETRIC,
	TOPVIEW,
	OBLIQUE,
	PERSPECTIVE,
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
	t_type		type;
	t_preset	preset;
	int			click_x;
	int			click_y;
	int			click_btn;
	bool		show_instr;
}	t_view_conf;

t_view_conf	*construct_view_conf(void);

#endif
