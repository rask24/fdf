/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_conf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:43:02 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 00:28:53 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CONF_H
# define MLX_CONF_H

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

# define WIN_TITLE  "fdf"
# define WIN_HEIGHT 800
# define WIN_WIDTH  1080

t_mlx_conf	*construct_mlx_conf(void);

#endif
