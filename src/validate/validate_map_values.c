/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:44:53 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 17:44:42 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

#include "data.h"
#include "libft.h"
#include "utils.h"

#include "validate_internal.h"

static void	_validate_map_values_internal(char *str)
{
	char	*endptr;
	long	val;

	while (true)
	{
		while (ft_isblank(*str))
			str++;
		if (*str == '\0' || *str == '\n')
			break ;
		val = ft_strtol(str, &endptr, 10);
		if (val < INT_MIN / DEFAULT_Z_SCALE || INT_MAX / DEFAULT_Z_SCALE < val)
			error_exit(INV_MAP_VALUE_ERR_MSG);
		if (*endptr == ',')
		{
			str = endptr + 3;
			val = ft_strtol(str, &endptr, 16);
			if (val < COLOR_LOWER_BOUND || COLOR_UPPER_BOUND < val)
				error_exit(INV_MAP_VALUE_ERR_MSG);
		}
		str = endptr;
	}
}

void	validate_map_values(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		_validate_map_values_internal(map[i]);
		i++;
	}
}
