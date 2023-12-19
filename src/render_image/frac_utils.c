/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:02:06 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/19 19:02:14 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	fpart(double x)
{
	return (x - floor(x));
}

double	rfpart(double x)
{
	return (1 - fpart(x));
}
