/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:35:40 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/11 13:33:17 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_points(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		free(map.points[i]);
		i++;
	}
	free(map.points);
}

// TODO: delete
void	dev(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			printf("(%d, %d, %d) #%#X\n",
				map.points[i][j].x,
				map.points[i][j].y,
				map.points[i][j].z,
				map.points[i][j].color);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;

	check_args(argc, argv);
	check_map(argv[1]);
	extract_map_info(&map, argv[1]);
	convert_points_to_isometric(&map);
	set_mlx(&mlx);
	render_image(map, mlx);
	handle_events(mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
