/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:24:54 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 00:41:23 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_INTERNAL_H
# define RENDER_INTERNAL_H

# include "ctx.h"

# define STR_INTERVAL	20

# define LABEL_X_OFFSET	920
# define LABEL_Y_OFFSET	20

# define SHRINK_FACTOR	0.5

typedef struct s_line_vars
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		c1;
	int		c2;
	int		color;
	double	*depth_buffer;
}	t_line_vars;

void	plot_pixel(t_ctx *ctx, int win_x, int win_y, int color);
void	plot_line(t_ctx *ctx, t_point p1, t_point p2, double *depth_buffer);
void	render_image(t_ctx *ctx);
void	render_instructions(t_ctx *ctx);

#endif
