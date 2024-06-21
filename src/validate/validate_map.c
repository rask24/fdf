/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:02:08 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 19:44:38 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"
#include "utils.h"

#include "validate_internal.h"

void	validate_map(char *file_path)
{
	char	**map;

	map = file_to_lines(file_path);
	if (map == NULL)
		error_exit(strerror(errno));
	if (map[0] == NULL)
		error_exit(EMPTY_MAP_ERR_MSG);
	validate_rectangle_map(map);
	validate_map_format(map);
	validate_map_values(map);
	ft_free_strs(map);
}
