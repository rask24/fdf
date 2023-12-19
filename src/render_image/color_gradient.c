/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:44:21 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/18 19:01:39 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	_calc_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

static int	_calc_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

static int	_calc_b(int trgb)
{
	return (trgb & 0xFF);
}

int	color_gradient(int color1, int color2, double ratio)
{
	int	r;
	int	g;
	int	b;

	r = _calc_r(color1) + ratio * (_calc_r(color2) - _calc_r(color1));
	g = _calc_g(color1) + ratio * (_calc_g(color2) - _calc_g(color1));
	b = _calc_b(color1) + ratio * (_calc_b(color2) - _calc_b(color1));
	return (r << 16 | g << 8 | b);
}
