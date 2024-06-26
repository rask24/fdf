/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:29:49 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/25 21:10:32 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "libft.h"
#include "utils.h"
#include "view_conf.h"

#include "data_internal.h"

t_data	*construct_data(char *file_path)
{
	char	**map;
	t_data	*data;

	map = file_to_lines(file_path);
	if (map == NULL)
		error_exit(strerror(errno));
	data = malloc(sizeof(t_data));
	if (data == NULL)
		error_exit(strerror(errno));
	init_cols(data, map);
	init_rows(data, map);
	init_orig_points(data, map);
	init_orig_z_min_max(data);
	init_points(data);
	init_colors(data, DEFAULT);
	ft_free_strs(map);
	return (data);
}
