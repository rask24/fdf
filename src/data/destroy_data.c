/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 02:54:16 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 03:13:40 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "data.h"

static void	free_points(t_point **points, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(points[i]);
		i++;
	}
	free(points);
}

void	destroy_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->orig_points)
		free_points((t_point **)data->orig_points, data->rows);
	if (data->points)
		free_points(data->points, data->rows);
	free(data);
}
