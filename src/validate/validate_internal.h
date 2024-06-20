/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:33:59 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/21 02:27:53 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_INTERNAL_H
# define VALIDATE_INTERNAL_H

# define EXE_NAME "fdf"

# define INV_ARGS_ERR_MSG "Invalid number of arguments"
# define INV_FILE_FORMAT_ERR_MSG "Invalid file format"
# define MAP_NOT_RECT_ERR_MSG "Map is not a rectangle"

void	validate_rectangle_map(char **map);

#endif
