/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rectangle_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 02:05:29 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 19:59:06 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"
#include "utils.h"

#include "validate_internal.h"

static size_t	_count_elements(char *str)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (!is_delimiter(str[i]) && is_delimiter(str[i + 1]))
			cnt++;
		i++;
	}
	return (cnt);
}

void	validate_rectangle_map(char **map)
{
	size_t	i;
	size_t	init_cnt;

	i = 0;
	init_cnt = _count_elements(map[0]);
	if (init_cnt == 0)
		error_exit(MAP_FIRST_LINE_ERR_MSG);
	if (init_cnt == 1 && map[1] == NULL)
		error_exit(MAP_HAS_ONLY_ONE_ELEMENT_ERR_MSG);
	while (map[i])
	{
		if (_count_elements(map[i]) != init_cnt)
			error_exit(MAP_NOT_RECT_ERR_MSG);
		i++;
	}
}
