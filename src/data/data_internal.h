/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:50:42 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 20:01:55 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_INTERNAL_H
# define DATA_INTERNAL_H

# include "data.h"

# define DEFAULT_COLOR_FLAG -1

void	init_cols(t_data *data, char **map);
void	init_rows(t_data *data, char **map);
void	init_orig_points(t_data *data, char **map);
void	init_z_min_max(t_data *data);

#endif
