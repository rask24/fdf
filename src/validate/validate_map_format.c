/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:02:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 16:57:11 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

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
		if (str == endptr || !is_delimiter(*endptr))
		{
			ft_dprintf(STDERR_FILENO, "%s: %s\n",
				EXE_NAME, INV_MAP_FORMAT_ERR_MSG);
			exit(1);
		}
		str = endptr;
	}
}

// valid format: <blank><decimal integer>(,<hex integer>)<delimiter>
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
