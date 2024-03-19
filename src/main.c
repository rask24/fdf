/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:35:40 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/18 20:07:25 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifdef DEV

void	free_points(t_ctx ctx)
{
	int	i;

	i = 0;
	while (i < ctx.map_height)
	{
		free(ctx.points[i]);
		i++;
	}
	free(ctx.points);
}

void	dev(t_ctx ctx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx.map_height)
	{
		j = 0;
		while (j < ctx.map_witdh)
		{
			printf("(%f, %f, %f) #%#X\n",
				ctx.points[i][j].x,
				ctx.points[i][j].y,
				ctx.points[i][j].z,
				ctx.points[i][j].color);
			j++;
		}
		i++;
	}
}

#endif

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	validate_args(argc, argv);
	validate_map(argv[1]);
	extract_map_info(&ctx, argv[1]);
	convert_points_to_isometric(&ctx);
	set_mlx(&ctx);
	render_image(&ctx);
	handle_events(&ctx);
	mlx_loop(ctx.mlx_ptr);
	return (0);
}
