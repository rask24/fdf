/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:02:08 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 19:17:12 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"

#include "validate_internal.h"

void	validate_map(char *file_path)
{
	char	**map;

	map = file_to_lines(file_path);
	if (map == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s\n", EXE_NAME, strerror(errno));
		exit(1);
	}
	if (map[0] == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s\n", EXE_NAME, EMPTY_MAP_ERR_MSG);
		exit(1);
	}
	validate_rectangle_map(map);
	validate_map_format(map);
	ft_free_strs(map);
}
