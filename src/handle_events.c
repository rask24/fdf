/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:13:20 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/11 13:38:46by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	_exit_window(void)
{
	exit(0);
	return (0);
}

static int	_handle_keydown(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == KEY_ESCAPE)
		_exit_window();
	if (keycode == KEY_ARROW_DOWN)
	{
		printf("%p\n", mlx->mlx_ptr);
		printf("%p\n", mlx->img_ptr);
		printf("%p\n", mlx->data_addr);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		// ft_bzero(mlx->data_addr,
		// 	WIN_HEIGHT * WIN_WIDTH * (mlx->bits_per_pixel / 8));
		// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return (0);
}

void	handle_events(t_mlx mlx)
{
	mlx_hook(mlx.win_ptr, ON_KEYDOWN, KEY_PRESS_MASK, _handle_keydown, &mlx);
	mlx_hook(mlx.win_ptr, ON_DESTROY, NO_EVENT_MASK, _exit_window, NULL);
}
