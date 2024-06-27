/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_conf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:43:02 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 02:59:34 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CONF_H
# define MLX_CONF_H

# include "key_conf.h"

# define WIN_TITLE	"fdf"
# define WIN_HEIGHT	800
# define WIN_WIDTH	1080
# define WIN_MARGIN	120

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

typedef enum e_mouse
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
}	t_mouse;

t_mlx_conf	*construct_mlx_conf(void);
void		destroy_mlx_conf(t_mlx_conf *mlx_conf);

void		reset_image(t_mlx_conf *mlx_conf);

#endif
