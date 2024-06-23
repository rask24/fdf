/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_z_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:09:46 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 17:27:21 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <limits.h>

#include "data.h"
#include "libft.h"

#include "data_internal.h"

void	init_z_min_max(t_data *data)
{
	int	i;
	int	j;
	int	z;

	data->z_min = INT_MAX;
	data->z_max = INT_MIN;
	for (i = 0; i < data->rows; i++)
	{
		for (j = 0; j < data->cols; j++)
		{
			z = (int)data->points[i][j].z;
			ft_chmin(&data->z_min, z);
			ft_chmax(&data->z_max, z);
		}
	}
}
