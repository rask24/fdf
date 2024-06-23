/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:35:27 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 16:46:51 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "data.h"

t_point	rotate_x(t_point p, double angle)
{
	t_point	new;

	new = (t_point)
	{
		.x = p.x,
		.y = p.y * cos(angle) - p.z * sin(angle),
		.z = p.y * sin(angle) + p.z * cos(angle),
		.color = p.color
	};
	return (new);
}

t_point	rotate_y(t_point p, double angle)
{
	t_point	new;

	new = (t_point)
	{
		.x = p.x * cos(angle) + p.z * sin(angle),
		.y = p.y,
		.z = -p.x * sin(angle) + p.z * cos(angle),
		.color = p.color,
	};
	return (new);
}

t_point	rotate_z(t_point p, double angle)
{
	t_point	new;

	new = (t_point)
	{
		.x = p.x * cos(angle) - p.y * sin(angle),
		.y = p.x * sin(angle) + p.y * cos(angle),
		.z = p.z,
		.color = p.color,
	};
	return (new);
}
