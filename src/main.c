/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:01:51 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/23 00:26:12 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "ctx.h"
#include "mlx.h"
#include "render.h"
#include "validate.h"
#include "utils.h"

static t_ctx	*_construct_ctx(char *file_path)
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (ctx == NULL)
		error_exit(strerror(errno));
	ctx->data = construct_data(file_path);
	ctx->mlx_conf = construct_mlx_conf();
	ctx->view_conf = construct_view_conf();
	return (ctx);
}

int	main(int argc, char **argv)
{
	t_ctx	*ctx;

	validate_arguments(argc, argv);
	validate_map(argv[1]);
	ctx = _construct_ctx(argv[1]);
	mlx_put_image_to_window(ctx->mlx_conf->p_mlx,
		ctx->mlx_conf->p_win, ctx->mlx_conf->p_img, 0, 0);
	render(ctx);
	mlx_loop(ctx->mlx_conf->p_mlx);
	return (EXIT_SUCCESS);
}
