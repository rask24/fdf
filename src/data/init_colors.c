/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:02:42 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 17:03:06 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

#include "data_internal.h"

void	init_colors(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->points[i][j].color == DEFAULT_COLOR_FLAG)
				data->points[i][j].color = DEFAULT_COLOR;
			j++;
		}
		i++;
	}
}
