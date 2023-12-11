/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:13:20 by reasuke           #+#    #+#             */
/*   Updated: 2023/12/11 13:29:51 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	_exit_window(void)
{
	exit(0);
	return (0);
}

static int	_handle_keydown(int keycode)
{
	if (keycode == KEY_ESCAPE)
		_exit_window();
	return (0);
}

void	handle_events(t_mlx mlx)
{
	mlx_hook(mlx.win_ptr, ON_KEYDOWN, KEY_PRESS_MASK, _handle_keydown, NULL);
	mlx_hook(mlx.win_ptr, ON_DESTROY, NO_EVENT_MASK, _exit_window, NULL);
}
