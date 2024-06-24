/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:58:39 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 17:01:36 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	interpolate_color(int color1, int color2, double ratio)
{
	int	red;
	int	green;
	int	blue;

	red = (int)(((color2 >> 16) & 0xFF) * ratio
			+ ((color1 >> 16) & 0xFF) * (1 - ratio));
	green = (int)(((color2 >> 8) & 0xFF) * ratio
			+ ((color1 >> 8) & 0xFF) * (1 - ratio));
	blue = (int)((color2 & 0xFF) * ratio
			+ (color1 & 0xFF) * (1 - ratio));
	return ((red << 16) | (green << 8) | blue);
}
