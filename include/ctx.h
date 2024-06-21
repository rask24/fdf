/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:02:16 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 02:03:10 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "data.h"
# include "mlx_conf.h"
# include "view_conf.h"

typedef struct s_ctx
{
	t_data		*data;
	t_view_conf	*view_conf;
	t_mlx_conf	*mlx_conf;
}	t_ctx;

#endif
