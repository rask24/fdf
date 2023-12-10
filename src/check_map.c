/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:15:56 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/10 14:35:14 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_check_format(char **line_array)
{
	char	*line;
	bool	flag_comma;

	while (*line_array)
	{
		line = *line_array;
		flag_comma = false;
		errno = 0;
		while (*line)
		{
			if (flag_comma)
				ft_strtol(line, &line, 16);
			else
				ft_strtol(line, &line, 10);
			if (!(*line == ' ' || *line == '\n' || *line == ','))
				exit_with_error("invalid file format: invalid charactor");
			if (*line == ','
				&& (flag_comma || errno || !(line[1] == '0' && line[2] == 'x')))
				exit_with_error("invalid file format: invalid format");
			flag_comma = *line == ',';
			line++;
		}
		line_array++;
	}
}

static int	_calc_map_width(char *line)
{
	int		width;

	width = 0;
	while (*line)
	{
		if (ft_isalnum(*line)
			&& (line[1] == ' ' || line[1] == '\n' || line[1] == '\t'))
			width++;
		line++;
	}
	return (width);
}

static void	_check_rectangle(char **line_array)
{
	int	width;
	int	prev;

	width = 0;
	prev = 0;
	while (*line_array)
	{
		width = _calc_map_width(*line_array);
		if (prev && prev != width)
			exit_with_error("invalid format: not a rectangle map");
		prev = width;
		line_array++;
	}
}

void	check_map(char *file_path)
{
	char	**line_array;

	line_array = file_to_line_array(file_path);
	if (!line_array)
		exit_with_error(strerror(errno));
	_check_format(line_array);
	_check_rectangle(line_array);
	ft_free_strs(line_array);
}
