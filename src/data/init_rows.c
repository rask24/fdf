/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:45:51 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 16:13:10 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	init_rows(t_data *data, char **map)
{
	int	cnt;

	cnt = 0;
	while (map[cnt])
		cnt++;
	data->rows = cnt;
}
