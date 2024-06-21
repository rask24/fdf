/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rectangle_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 02:05:29 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 19:39:59 by reasuke          ###   ########.fr       */
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
	while (map[i])
	{
		if (_count_elements(map[i]) != init_cnt)
			error_exit(MAP_NOT_RECT_ERR_MSG);
		i++;
	}
}
