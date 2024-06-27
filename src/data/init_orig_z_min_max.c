/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_orig_z_min_max.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:09:46 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/26 20:43:36 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "data.h"
#include "libft.h"

#include "data_internal.h"

void	init_orig_z_min_max(t_data *data)
{
	int		i;
	int		j;
	double	z;

	data->orig_z_min = INT_MAX;
	data->orig_z_max = INT_MIN;
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			z = data->orig_points[i][j].z;
			ft_fchmin(&data->orig_z_min, z);
			ft_fchmax(&data->orig_z_max, z);
			j++;
		}
		i++;
	}
}
