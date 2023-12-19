/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ratio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:10:09 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/19 19:10:20 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	calc_ratio(t_point p0, t_point p1, double x, double y)
{
	double	dist;

	dist = sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y));
	return (sqrt((x - p0.x) * (x - p0.x) + (y - p0.y) * (y - p0.y)) / dist);
}
