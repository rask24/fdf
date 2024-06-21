/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:02:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 20:18:26 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft.h"
#include "utils.h"

#include "validate_internal.h"

void	_validate_map_format_internal(char *str)
{
	char	*endptr;

	while (true)
	{
		while (ft_isblank(*str))
			str++;
		if (*str == '\0' || *str == '\n')
			break ;
		ft_strtol(str, &endptr, 10);
		if (str != endptr && ft_strncmp(endptr, ",0x", 3) == 0)
		{
			str = endptr + 1;
			if (is_delimiter(str[2]))
				error_exit(INV_MAP_FORMAT_ERR_MSG);
			ft_strtol(str, &endptr, 16);
		}
		if (str == endptr || !is_delimiter(*endptr))
			error_exit(INV_MAP_FORMAT_ERR_MSG);
		str = endptr;
	}
}

// valid format: <blank><decimal integer>(,0x<hex integer>)<delimiter>
void	validate_map_format(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		_validate_map_format_internal(map[i]);
		i++;
	}
}
