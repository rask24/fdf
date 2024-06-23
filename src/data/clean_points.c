/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:47:04 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 20:47:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "data.h"

void	clean_points(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		free(data->points[i]);
		i++;
	}
	free(data->points);
	data->points = NULL;
}
