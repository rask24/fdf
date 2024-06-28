/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:33:59 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 19:58:35 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_INTERNAL_H
# define VALIDATE_INTERNAL_H

# define INV_ARGS_ERR_MSG					"Invalid number of arguments"
# define INV_FILE_FORMAT_ERR_MSG			"Invalid file format"
# define EMPTY_MAP_ERR_MSG					"Empty map"
# define MAP_FIRST_LINE_ERR_MSG				"First line of map has no elements"
# define MAP_HAS_ONLY_ONE_ELEMENT_ERR_MSG	"Map has only one element"
# define MAP_NOT_RECT_ERR_MSG				"Map is not a rectangle"
# define INV_MAP_FORMAT_ERR_MSG				"Invalid map format"
# define INV_MAP_VALUE_ERR_MSG				"Invalid map value"

# define COLOR_LOWER_BOUND	0
# define COLOR_UPPER_BOUND	0xFFFFFF

void	validate_rectangle_map(char **map);
void	validate_map_format(char **map);
void	validate_map_values(char **map);

#endif
