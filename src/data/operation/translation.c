/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:32:52 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 23:06:21 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_point	translate_x(t_point p, double param)
{
	p.x += param;
	return (p);
}

t_point	translate_y(t_point p, double param)
{
	p.y += param;
	return (p);
}
