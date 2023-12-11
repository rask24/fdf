/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:46:52 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/11 13:04:29 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CONFIG_H
# define MLX_CONFIG_H

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

enum
{
	NO_EVENT_MASK = 0L,
	KEY_PRESS_MASK = 1L << 0,
};

# ifdef __linux__
#  define KEY_ESCAPE      65307
#  define KEY_ARROW_UP    65362
#  define KEY_ARROW_DOWN  65364
#  define KEY_ARROW_LEFT  65361
#  define KEY_ARROW_RIGHT 65363
# endif

# ifdef __APPLE__
#  define KEY_ESCAPE      53
#  define KEY_ARROW_UP    126
#  define KEY_ARROW_DOWN  125
#  define KEY_ARROW_LEFT  123
#  define KEY_ARROW_RIGHT 124
# endif

#endif
