/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:02:08 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 02:27:53 by reasuke          ###   ########.fr       */
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
	validate_rectangle_map(map);
	ft_free_strs(map);
}
