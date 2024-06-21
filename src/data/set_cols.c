/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:45:15 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 22:47:05 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "utils.h"

void	set_cols(t_data *data, char **map)
{
	int		cnt;
	int		i;
	char	*str;

	cnt = 0;
	i = 0;
	str = map[0];
	while (str[i])
	{
		if (!is_delimiter(str[i]) && is_delimiter(str[i + 1]))
			cnt++;
		i++;
	}
	data->cols = cnt;
}

