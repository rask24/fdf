/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:02:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 19:24:26 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "validate_internal.h"

static void	_error_exit(char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s: %s\n", EXE_NAME, msg);
	exit(1);
}

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
			str = endptr + 3;
			if (is_delimiter(*str))
				_error_exit(INV_MAP_FORMAT_ERR_MSG);
			ft_strtol(str, &endptr, 16);
		}
		if (str == endptr || !is_delimiter(*endptr))
			_error_exit(INV_MAP_FORMAT_ERR_MSG);
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
