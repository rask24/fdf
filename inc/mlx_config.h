/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:46:52 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/18 19:35:00 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CONFIG_H
# define MLX_CONFIG_H

typedef enum e_status
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
}			t_status;

typedef enum e_mask
{
	NO_EVENT_MASK = 0L,
	KEY_PRESS_MASK = 1L << 0,
}	t_mask;

# ifdef __linux__
#  define KEY_A				97
#  define KEY_D				100
#  define KEY_W				119
#  define KEY_S				115
#  define KEY_COMMNA		44
#  define KEY_DOT			46
#  define KEY_ESCAPE		65307
#  define KEY_ARROW_UP		65362
#  define KEY_ARROW_DOWN	65364
#  define KEY_ARROW_LEFT	65361
#  define KEY_ARROW_RIGHT	65363
#  define KEY_PLUS			65361
#  define KEY_MINUS			65363
# endif

# ifdef __APPLE__
#  define KEY_A				0
#  define KEY_D				2
#  define KEY_W				13
#  define KEY_S				1
#  define KEY_COMMNA		43
#  define KEY_DOT			47
#  define KEY_ESCAPE		53
#  define KEY_ARROW_UP		126
#  define KEY_ARROW_DOWN	125
#  define KEY_ARROW_LEFT	123
#  define KEY_ARROW_RIGHT	124
#  define KEY_PLUS			24
#  define KEY_MINUS			27
# endif

#endif
