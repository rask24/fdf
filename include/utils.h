/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:33:10 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/25 20:18:27 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

# define EXE_NAME	"fdf"

void	error_exit(char *msg);
int		interpolate_color(int color1, int color2, double ratio);
bool	is_delimiter(char c);

#endif
