/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:59 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/20 15:31:49 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_set_map_size(t_ctx *ctx, char **line_array)
{
	char	*first_line;

	first_line = *line_array;
	ctx->map_witdh = 0;
	while (*first_line)
	{
		if (ft_isalnum(*first_line)
			&& (first_line[1] == ' '
				|| first_line[1] == '\n' || first_line[1] == '\t'))
			ctx->map_witdh++;
		first_line++;
	}
	ctx->map_height = 0;
	while (line_array[ctx->map_height])
		ctx->map_height++;
}

static void	_alloc_points(t_ctx *ctx)
{
	int	i;

	ctx->points = malloc(sizeof(t_point) * ctx->map_height);
	if (!ctx->points)
		exit_with_error(strerror(errno));
	i = 0;
	while (i < ctx->map_height)
	{
		ctx->points[i] = malloc(sizeof(t_point) * ctx->map_witdh);
		if (!ctx->points[i])
			exit_with_error(strerror(errno));
		i++;
	}
}

static void	_set_points_fixed_y(t_ctx *ctx, int y, char *line)
{
	int		x;
	bool	flag_color;

	x = 0;
	flag_color = false;
	while (x < ctx->map_witdh)
	{
		ctx->points[y][x].x = x;
		ctx->points[y][x].y = y;
		ctx->points[y][x].color = NO_COLOR_SPEC;
		if (flag_color)
			ctx->points[y][x].color = ft_strtol(line, &line, 16);
		else
			ctx->points[y][x].z = ft_strtol(line, &line, 10);
		flag_color = *line == ',';
		line++;
		if (!flag_color)
			x++;
	}
}

static void	_set_points(t_ctx *ctx, char **line_array)
{
	int		x;
	int		y;

	y = 0;
	while (y < ctx->map_height)
	{
		_set_points_fixed_y(ctx, y, line_array[y]);
		y++;
	}
	y = 0;
	while (y < ctx->map_height)
	{
		x = 0;
		while (x < ctx->map_witdh)
		{
			if (ctx->points[y][x].color == NO_COLOR_SPEC
				&& ctx->points[y][x].z)
				ctx->points[y][x].color = DEFAULT_COLOR_TOP;
			else if (ctx->points[y][x].color == NO_COLOR_SPEC)
				ctx->points[y][x].color = DEFAULT_COLOR_BOTTOM;
			x++;
		}
		y++;
	}
}

void	extract_map_info(t_ctx *ctx, char *file_path)
{
	char	**line_array;

	line_array = file_to_line_array(file_path);
	if (!line_array)
		exit_with_error(strerror(errno));
	_set_map_size(ctx, line_array);
	_alloc_points(ctx);
	_set_points(ctx, line_array);
	ft_free_strs(line_array);
}
