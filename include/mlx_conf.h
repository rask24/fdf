/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_conf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:43:02 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 19:56:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CONF_H
# define MLX_CONF_H

# include "key_conf.h"

# define WIN_TITLE	"fdf"
# define WIN_HEIGHT	800
# define WIN_WIDTH	1080

typedef struct s_mlx_conf
{
	void	*p_mlx;
	void	*p_win;
	void	*p_img;
	char	*p_data;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}	t_mlx_conf;

typedef enum e_status
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
}	t_status;

typedef enum e_mask
{
	NO_EVENT_MASK = 0L,
	KEY_PRESS_MASK = 1L << 0,
}	t_mask;

t_mlx_conf	*construct_mlx_conf(void);

#endif
