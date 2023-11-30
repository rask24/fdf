/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_line_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:22:21 by reasuke           #+#    #+#             */
/*   Updated: 2023/11/28 22:11:45 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_count_lines(char *file_path)
{
	int		fd;
	int		num_lines;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	num_lines = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (errno != 0)
				return (ERROR);
			break ;
		}
		free(line);
		num_lines++;
	}
	close(fd);
	return (num_lines);
}

static int	_fill_line_array(char **line_array, int num_lines, char *file_path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	i = 0;
	while (i < num_lines)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (errno != 0)
			{
				ft_free_strs(line_array);
				close(fd);
				return (ERROR);
			}
			break ;
		}
		line_array[i] = line;
		i++;
	}
	line_array[i] = NULL;
	close(fd);
	return (OK);
}

char	**file_to_line_array(char *file_path)
{
	int		num_lines;
	char	**line_array;

	num_lines = _count_lines(file_path);
	if (num_lines == ERROR)
		return (NULL);
	line_array = malloc(sizeof(char *) * (num_lines + 1));
	if (!line_array)
		return (NULL);
	if (_fill_line_array(line_array, num_lines, file_path) == ERROR)
		return (NULL);
	return (line_array);
}
