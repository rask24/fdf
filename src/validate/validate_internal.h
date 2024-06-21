/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:33:59 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 19:56:04 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_INTERNAL_H
# define VALIDATE_INTERNAL_H

# include <stdbool.h>
# include <limits.h>

# define INV_ARGS_ERR_MSG "Invalid number of arguments"
# define INV_FILE_FORMAT_ERR_MSG "Invalid file format"
# define EMPTY_MAP_ERR_MSG "Empty map"
# define MAP_NOT_RECT_ERR_MSG "Map is not a rectangle"
# define INV_MAP_FORMAT_ERR_MSG "Invalid map format"
# define INV_MAP_VALUE_ERR_MSG "Invalid map values"

# define Z_LOWER_BOUND INT_MIN
# define Z_UPPER_BOUND INT_MAX
# define COLOR_LOWER_BOUND 0
# define COLOR_UPPER_BOUND 0xFFFFFF


void	validate_rectangle_map(char **map);
void	validate_map_format(char **map);
void	validate_map_values(char **map);
bool	is_delimiter(char c);

#endif
