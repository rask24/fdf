/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:36:09 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 21:35:42 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_point	scale_x(t_point p, double param)
{
	p.x *= param;
	return (p);
}

t_point	scale_y(t_point p, double param)
{
	p.y *= param;
	return (p);
}

t_point	scale_z(t_point p, double param)
{
	p.z *= param;
	return (p);
}

t_point	scale(t_point p, double param)
{
	p.x *= param;
	p.y *= param;
	p.z *= param;
	return (p);
}
