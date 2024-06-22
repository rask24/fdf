/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:21:11 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 22:30:29 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

#include "data_internal.h"

void	apply_operation(t_data *data, t_operation op, double param)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			data->points[i][j] = op(data->points[i][j], param);
			j++;
		}
		i++;
	}
}
