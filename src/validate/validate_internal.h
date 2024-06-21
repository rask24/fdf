/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:33:59 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 19:38:51 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_INTERNAL_H
# define VALIDATE_INTERNAL_H

# include <stdbool.h>

# define EXE_NAME "fdf"

# define INV_ARGS_ERR_MSG "Invalid number of arguments"
# define INV_FILE_FORMAT_ERR_MSG "Invalid file format"
# define EMPTY_MAP_ERR_MSG "Empty map"
# define MAP_NOT_RECT_ERR_MSG "Map is not a rectangle"
# define INV_MAP_FORMAT_ERR_MSG "Invalid map format"

void	validate_rectangle_map(char **map);
void	validate_map_format(char **map);
bool	is_delimiter(char c);

#endif
