/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:59 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/13 19:00:32 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_set_map_size(t_map *map, char **line_array)
{
	char	*first_line;

	first_line = *line_array;
	map->width = 0;
	while (*first_line)
	{
		if (ft_isalnum(*first_line)
			&& (first_line[1] == ' '
				|| first_line[1] == '\n' || first_line[1] == '\t'))
			map->width++;
		first_line++;
	}
	map->height = 0;
	while (line_array[map->height])
		map->height++;
}

static void	_alloc_points(t_map *map)
{
	int	i;

	map->points = malloc(sizeof(t_point) * map->height);
	if (!map->points)
		exit_with_error(strerror(errno));
	i = 0;
	while (i < map->height)
	{
		map->points[i] = malloc(sizeof(t_point) * map->width);
		if (!map->points[i])
			exit_with_error(strerror(errno));
		i++;
	}
}

static void	_set_points_fixed_y(t_map *map, int y, char *line)
{
	int		x;
	bool	flag_color;

	x = 0;
	flag_color = false;
	while (x < map->width)
	{
		map->points[y][x].x = x;
		map->points[y][x].y = y;
		map->points[y][x].color = NOT_SPECIFIED;
		if (flag_color)
			map->points[y][x].color = ft_strtol(line, &line, 16);
		else
			map->points[y][x].z = ft_strtol(line, &line, 10);
		flag_color = *line == ',';
		line++;
		if (!flag_color)
			x++;
	}
}

static void	_set_points(t_map *map, char **line_array)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		_set_points_fixed_y(map, y, line_array[y]);
		y++;
	}
	y = 0;
	map->min_val = INT_MAX;
	map->max_val = INT_MIN;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->points[y][x].color == NOT_SPECIFIED
				&& map->points[y][x].z)
				map->points[y][x].color = 0xAABBC;
			else if (map->points[y][x].color == NOT_SPECIFIED)
				map->points[y][x].color = 0xDDDDDD;
			ft_chmin(&map->min_val, map->points[y][x].z);
			ft_chmax(&map->max_val, map->points[y][x].z);
			x++;
		}
		y++;
	}
}

void	extract_map_info(t_map *map, char *file_path)
{
	char	**line_array;

	line_array = file_to_line_array(file_path);
	if (!line_array)
		exit_with_error(strerror(errno));
	_set_map_size(map, line_array);
	_alloc_points(map);
	_set_points(map, line_array);
	ft_free_strs(line_array);
}
