/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:24:03 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/22 15:44:12 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_data
{
	const t_point	**orig_points;
	t_point			**points;
	int				rows;
	int				cols;
}	t_data;

t_data	*construct_data(char *file_path);

#endif
